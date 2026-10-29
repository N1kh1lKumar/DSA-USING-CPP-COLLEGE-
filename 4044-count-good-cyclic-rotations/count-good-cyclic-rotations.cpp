class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        vector<int> v = nums;
        int n = v.size(), h = n / 2, ans = 0;
        long long s1 = 0, s2 = 0;
        
        for (int i = 0; i < h; ++i) {
            s1 += v[i];
            s2 += v[i + h];
        }
        if (s1 > s2) ans++;
        
        for (int i = 1; i < n; ++i) {
            s1 = s1 - v[i - 1] + v[(i - 1 + h) % n];
            s2 = s2 - v[(i - 1 + h) % n] + v[i - 1];
            if (s1 > s2) ans++;
        }
        
        return ans;        
    }
};
