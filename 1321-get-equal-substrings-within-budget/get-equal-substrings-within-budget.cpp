class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start = 0, length = 0, cost = 0;

        for (int end = 0; end < s.size(); end++) {
            cost += abs(s[end] - t[end]);

            while (cost > maxCost) {
                cost -= abs(s[start] - t[start]);
                start++;
            }

            length = max(length, end - start + 1);
        }

        return length;
    }
};