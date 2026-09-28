class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int tempCount = 0;
        for (char x : s) {

            if (x == '(') {
                tempCount++;
                count = max(count, tempCount);
            } else if (x == ')') {
                tempCount--;
            }
        }
        return count;
    }
};