class Solution {
public:
    int countCommas(int n) {
        if(n<=999)   return 0;
        int ans =0;
        n = n-999;
        ans += n;
        return ans;
    }
};