
class Solution {
public:
    int minInsertions(string s) {
        int minParentheses = 0;
        int open = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;
            } 
            else {
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    minParentheses++;
                }

                if (open > 0) {
                    open--;
                } 
                else {
                    minParentheses++;
                }
            }
        }

        // Every remaining '(' needs two ')'
        minParentheses += open * 2;

        return minParentheses;
    }
};