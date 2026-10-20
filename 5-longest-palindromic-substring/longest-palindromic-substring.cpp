class Solution {
public:
    string longestPalindrome(string s) {
        int startIndex = 0, maxLength = 1;

        for(int i = 0; i < s.size(); i++) {
            int start = i, end = i;

            while(start >= 0 && end < s.size() && s[start] == s[end]) {
                if(maxLength < end - start + 1) {
                    startIndex = start;
                    maxLength = end - start + 1;
                }
                start--;
                end++;
            }

            start = i;
            end = i + 1;

            while(start >= 0 && end < s.size() && s[start] == s[end]) {
                if(maxLength < end - start + 1) {
                    startIndex = start;
                    maxLength = end - start + 1;
                }
                start--;
                end++;
            }
        }

        return s.substr(startIndex, maxLength);
    }
};