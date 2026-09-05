class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> Mn(n);

        Mn[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            Mn[i] = min(nums[i], Mn[i + 1]);
        }

        int prefixMax = nums[0];

        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);

            int score = prefixMax - Mn[i];

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};