class Solution {
public:
    int reverseDegree(string s) {
        int result = 0;

        for (int i = 1; i <= s.size(); i++) {
            int product = (26 - (s[i-1] - 'a')) * i;
            result =  result + product;
        }
        return result;
    }
};