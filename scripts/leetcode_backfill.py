#!/usr/bin/env python3
"""
One-time LeetCode backfill.

Safety:
- Never overwrites an existing file.
- Writes recovered source only under LeetCode/<id>-<slug>/.
- Defaults to dry-run unless DRY_RUN is explicitly false.
- Stops rather than claiming a complete scan if LeetCode's solved-problem
  endpoint is unavailable or returns an unexpected/empty response.
"""
from __future__ import annotations

import os
import re
import sys
import time
from pathlib import Path
from typing import Any

import requests

GRAPHQL_URL = "https://leetcode.com/graphql/"
ROOT = Path(".")
REPORT = ROOT / "backfill-report.md"
SESSION = os.getenv("LEETCODE_SESSION", "").strip()
CSRF = os.getenv("LEETCODE_CSRF_TOKEN", "").strip()
USERNAME = os.getenv("LEETCODE_USERNAME", "").strip()
DRY_RUN = os.getenv("DRY_RUN", "true").lower() not in {"false", "0", "no"}
MAX_PROBLEMS = int(os.getenv("MAX_PROBLEMS", "0") or "0")
SLEEP_SECONDS = 0.6
TIMEOUT = 30

EXTENSIONS = {
    "cpp": "cpp", "c++": "cpp", "python": "py", "python3": "py",
    "java": "java", "javascript": "js", "typescript": "ts",
    "c": "c", "csharp": "cs", "c#": "cs", "golang": "go",
    "go": "go", "rust": "rs", "kotlin": "kt", "swift": "swift",
    "ruby": "rb", "scala": "scala", "php": "php", "mysql": "sql",
    "mssql": "sql", "oraclesql": "sql", "postgresql": "sql",
    "dart": "dart", "elixir": "ex", "erlang": "erl", "racket": "rkt",
    "bash": "sh", "shell": "sh", "pythonml": "py",
    "mssqlserver": "sql", "ms sql server": "sql", "oracle": "sql",
    "postgres": "sql", "plain sql": "sql", "objectivec": "m",
    "objective-c": "m", "ocaml": "ml", "fsharp": "fs",
}
LANG_ALIASES = {
    "cpp": "cpp", "c++": "cpp", "python": "python", "python3": "python3",
    "javascript": "javascript", "typescript": "typescript",
    "csharp": "csharp", "c#": "csharp", "golang": "golang",
    "go": "go", "mysql": "mysql", "mssql": "mssql",
    "oraclesql": "oraclesql", "postgresql": "postgresql",
}

def stop(message: str) -> None:
    print(f"::error::{message}")
    raise SystemExit(1)

def gql(query: str, variables: dict[str, Any] | None = None) -> dict[str, Any]:
    headers = {
        "Content-Type": "application/json",
        "Referer": "https://leetcode.com/",
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 Chrome/124 Safari/537.36",
        "x-csrftoken": CSRF,
        "x-requested-with": "XMLHttpRequest",
    }
    cookies = {"LEETCODE_SESSION": SESSION, "csrftoken": CSRF}
    try:
        response = requests.post(
            GRAPHQL_URL, json={"query": query, "variables": variables or {}},
            headers=headers, cookies=cookies, timeout=TIMEOUT
        )
    except requests.RequestException as exc:
        stop(f"LeetCode request failed: {type(exc).__name__}. Check the workflow logs and retry.")
    if response.status_code in (401, 403):
        stop("LeetCode rejected the session (401/403). Refresh LEETCODE_SESSION and LEETCODE_CSRF_TOKEN secrets.")
    if response.status_code == 429:
        stop("LeetCode rate-limited the workflow. Wait and run it again.")
    if not response.ok:
        # Include a short, sanitized response body so API/query errors are diagnosable.
        # Do not print request headers or cookie values.
        body = re.sub(r"\s+", " ", response.text or "").strip()
        body = body[:1200] if body else "(empty response body)"
        stop(
            f"LeetCode returned HTTP {response.status_code}. "
            f"Response body: {body}. No files were pushed."
        )
    try:
        payload = response.json()
    except ValueError:
        stop("LeetCode returned a non-JSON response (possibly a login or anti-bot page). No files were pushed.")
    if payload.get("errors"):
        msgs = "; ".join(str(e.get("message", "GraphQL error")) for e in payload["errors"])
        stop(f"LeetCode GraphQL error: {msgs}. No files were pushed.")
    if not isinstance(payload.get("data"), dict):
        stop("LeetCode response did not contain data. No files were pushed.")
    return payload["data"]

def verify_login() -> None:
    data = gql("query { userStatus { isSignedIn username } }")
    status = data.get("userStatus") or {}
    if not status.get("isSignedIn"):
        stop("LeetCode session is not signed in. Refresh the repository secrets.")
    actual = status.get("username")
    if USERNAME and actual and actual.lower() != USERNAME.lower():
        stop(f"LEETCODE_USERNAME does not match the signed-in account ({actual}).")
    print(f"Authenticated to LeetCode as {actual or USERNAME or '(username unavailable)'}.") 

def get_solved_questions() -> list[dict[str, Any]]:
    # userProgressQuestionList can be account/plan dependent. Fail closed if unavailable.
    query = """
    query userProgressQuestionList($filters: UserProgressQuestionListInput) {
      userProgressQuestionList(filters: $filters) {
        totalNum
        questions {
          frontendId
          title
          titleSlug
          difficulty
        }
      }
    }
    """
    questions: list[dict[str, Any]] = []
    skip = 0
    page_size = 100
    expected_total = None
    while True:
        data = gql(query, {"filters": {
            "questionStatus": "SOLVED", "skip": skip, "limit": page_size
        }})
        result = data.get("userProgressQuestionList")
        if not isinstance(result, dict) or not isinstance(result.get("questions"), list):
            stop("LeetCode did not provide the solved-question list. This endpoint may be unavailable on your account; no files were pushed.")
        if expected_total is None:
            expected_total = int(result.get("totalNum") or 0)
            if expected_total == 0 and not result["questions"]:
                stop("LeetCode returned zero solved questions. Refusing to treat this as a complete history.")
        batch = result["questions"]
        questions.extend(batch)
        print(f"Discovered {len(questions)} / {expected_total or '?'} solved problems.")
        if not batch or len(questions) >= (expected_total or 0):
            break
        skip += len(batch)
        if MAX_PROBLEMS and len(questions) >= MAX_PROBLEMS:
            questions = questions[:MAX_PROBLEMS]
            break
        time.sleep(SLEEP_SECONDS)
    # Deduplicate by slug and discard malformed rows.
    unique = {}
    for q in questions:
        if q.get("titleSlug") and q.get("frontendId") and q.get("title"):
            unique[q["titleSlug"]] = q
    out = list(unique.values())
    if MAX_PROBLEMS:
        out = out[:MAX_PROBLEMS]
    if not out:
        stop("No valid solved problems were returned. No files were pushed.")
    return out

def norm(value: str) -> str:
    return re.sub(r"[^a-z0-9]+", "", value.lower())

def language_key(lang: str) -> str:
    return re.sub(r"[^a-z0-9+#]+", "", lang.lower())

def existing_language_for_question(question: dict[str, Any], ext: str) -> bool:
    """Detect a same-language solution in this repo's existing LeetSync-style layout."""
    slug = norm(str(question.get("titleSlug", "")))
    title = norm(str(question.get("title", "")))
    qid = norm(str(question.get("frontendId", "")))
    for path in ROOT.rglob("*"):
        if not path.is_file() or ".git" in path.parts or path == REPORT:
            continue
        if path.suffix.lower().lstrip(".") != ext:
            continue
        # LeetSync-style repositories store files under <id>-<slug>/.
        # Also support folders named just <slug>, and older custom filenames.
        parts = [norm(part) for part in path.parts[:-1]]
        matching_folder = any(
            (slug and slug in part and (qid in part or part == slug))
            or (title and title in part and (qid in part or part == title))
            for part in parts
        )
        if matching_folder:
            return True
        # Fall back to the filename when a user flattened or renamed a solution.
        filename = norm(path.stem)
        if slug and (filename == slug or filename in {title, slug}):
            return True
    return False

def accepted_submissions(slug: str) -> list[dict[str, Any]]:
    query = """
    query submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {
      submissionList(
        offset: $offset
        limit: $limit
        lastKey: $lastKey
        questionSlug: $questionSlug
      ) {
        submissions { id statusDisplay lang timestamp }
      }
    }
    """
    data = gql(query, {"offset": 0, "limit": 20, "lastKey": None, "questionSlug": slug})
    result = data.get("submissionList") or {}
    submissions = result.get("submissions")
    if not isinstance(submissions, list):
        stop(f"Could not read submission history for '{slug}'. No files were pushed.")
    accepted = [s for s in submissions if str(s.get("statusDisplay", "")).lower() == "accepted" and s.get("id") and s.get("lang")]
    # Keep newest accepted submission per language.
    latest: dict[str, dict[str, Any]] = {}
    for sub in sorted(accepted, key=lambda s: int(s.get("timestamp") or 0), reverse=True):
        key = language_key(str(sub["lang"]))
        latest.setdefault(key, sub)
    return list(latest.values())

def fetch_code(submission_id: str) -> tuple[str, str]:
    query = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
        lang { name verboseName }
      }
    }
    """
    data = gql(query, {"submissionId": int(submission_id)})
    details = data.get("submissionDetails") or {}
    code = details.get("code")
    lang_value = details.get("lang") or ""
    lang = str(lang_value.get("name") if isinstance(lang_value, dict) else lang_value)
    if not isinstance(code, str) or not code.strip():
        return "", lang
    return code.rstrip() + "\n", lang

def write_report(lines: list[str], summary: dict[str, int]) -> None:
    text = [
        "# LeetCode backfill report", "",
        f"- Mode: **{'DRY RUN — no files written' if DRY_RUN else 'WRITE MODE'}**",
        f"- Solved problems inspected: {summary.get('problems', 0)}",
        f"- Accepted language variants found: {summary.get('accepted', 0)}",
        f"- Added / would add: {summary.get('added', 0)}",
        f"- Skipped as already present: {summary.get('existing', 0)}",
        f"- Unavailable or unsupported: {summary.get('unavailable', 0)}",
        "", "## Details", "", "| Result | Problem | Language | File / reason |",
        "|---|---|---|---|", *lines, ""
    ]
    REPORT.write_text("\n".join(text), encoding="utf-8")

def main() -> None:
    if not SESSION or not CSRF:
        stop("Missing LEETCODE_SESSION or LEETCODE_CSRF_TOKEN repository secret.")
    if not USERNAME:
        stop("Missing LEETCODE_USERNAME repository secret.")
    verify_login()
    questions = get_solved_questions()
    print(f"Checking accepted submissions for {len(questions)} solved problems.")
    report_lines: list[str] = []
    stats = {"problems": len(questions), "accepted": 0, "added": 0, "existing": 0, "unavailable": 0}
    main._added_paths = []
    for index, question in enumerate(questions, start=1):
        slug = str(question["titleSlug"])
        qid = str(question["frontendId"])
        title = str(question["title"])
        difficulty = str(question.get("difficulty") or "Unknown")
        try:
            subs = accepted_submissions(slug)
        except SystemExit:
            raise
        except Exception as exc:
            stop(f"Unexpected error while listing '{slug}' ({type(exc).__name__}). No files were pushed.")
        stats["accepted"] += len(subs)
        if not subs:
            report_lines.append(f"| No accepted submission found | {title} | — | `{slug}` |")
            stats["unavailable"] += 1
            continue
        for sub in subs:
            code, lang_name = fetch_code(str(sub["id"]))
            time.sleep(SLEEP_SECONDS)
            lang_raw = str(sub.get("lang") or lang_name or "")
            lang = language_key(lang_raw)
            ext = EXTENSIONS.get(lang) or EXTENSIONS.get(lang_raw.lower().replace(" ", ""))
            if not code:
                report_lines.append(f"| Source unavailable | {title} | {lang_raw} | submission `{sub['id']}` |")
                stats["unavailable"] += 1
                continue
            if not ext:
                report_lines.append(f"| Unsupported language | {title} | {lang_raw} | source not written |")
                stats["unavailable"] += 1
                continue
            if existing_language_for_question(question, ext):
                report_lines.append(f"| Skipped existing | {title} | {lang_raw} | matching problem/language file already exists |")
                stats["existing"] += 1
                continue
            # Match this repository's existing LeetSync layout at the repository root.
            folder = f"{qid}-{slug}"
            destination = ROOT / folder / f"{slug}.{ext}"
            # Never overwrite even if a prior file wasn't detected by heuristic.
            if destination.exists():
                report_lines.append(f"| Skipped existing | {title} | {lang_raw} | `{destination.as_posix()}` already exists |")
                stats["existing"] += 1
                continue
            if not DRY_RUN:
                destination.parent.mkdir(parents=True, exist_ok=True)
                # Exclusive creation prevents accidental overwrite, even if the repo changes.
                try:
                    with destination.open("x", encoding="utf-8") as handle:
                        handle.write(code)
                except FileExistsError:
                    report_lines.append(f"| Skipped existing | {title} | {lang_raw} | `{destination.as_posix()}` already exists |")
                    stats["existing"] += 1
                    continue
                main._added_paths.append(destination)
            report_lines.append(f"| {'Would add' if DRY_RUN else 'Added'} | {title} | {lang_raw} | `{destination.as_posix()}` |")
            stats["added"] += 1
        if index % 10 == 0:
            print(f"Checked {index}/{len(questions)} problems.")
        time.sleep(SLEEP_SECONDS)
    write_report(report_lines, stats)
    print("\nBackfill summary:")
    for key, value in stats.items():
        print(f"  {key}: {value}")
    # Manifest includes only files actually created by this run; do not stage pre-existing files.
    manifest_paths = getattr(main, "_added_paths", [])
    (ROOT / "backfill-added-files.txt").write_text(
        "".join(p.relative_to(ROOT).as_posix() + "\n" for p in manifest_paths), encoding="utf-8"
    )
    print(f"Report written to {REPORT}.")
    if DRY_RUN:
        print("Dry run finished. Review the uploaded report before running with dry_run=false.")
    else:
        print("Write mode finished. The manifest lists only files created during this run.")

if __name__ == "__main__":
    main()
