class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);

        if (k == 0)
            return ans;

        int sum = 0;

        if (k > 0) {
             for (int i = 1; i <= k; i++) {
                sum += nums[i % n];
            }

            for (int i = 0; i < n; i++) {
                ans[i] = sum;

                sum -= nums[(i + 1) % n];
                sum += nums[(i + k + 1) % n];
            }
        } else {
             k = -k;

            // Initial window: nums[n-k] ... nums[n-1]
            for (int i = n - k; i < n; i++) {
                sum += nums[i];
            }

            for (int i = 0; i < n; i++) {
                ans[i] = sum;

                sum -= nums[(i - k + n) % n];
                sum += nums[i];
            }
        }

        return ans;
    }
};
