class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;

        for (int start = 0; start + 2 < s.size(); start++) {
            if (s[start] != s[start + 1] && s[start + 1] != s[start + 2] && s[start] != s[start + 2]) {
                count++;
            }
        }

        return count;
    }
};
