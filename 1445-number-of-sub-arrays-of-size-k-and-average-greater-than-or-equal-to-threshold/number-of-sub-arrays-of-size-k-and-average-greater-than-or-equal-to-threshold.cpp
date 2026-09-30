class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int start = 0, end = 0, sum = 0;
        int count = 0;

        for (; end < nums.size(); end++) {
            sum += nums[end];

            if (end - start + 1 == k) {

                if (sum >= k * threshold) {
                    count++;
                }

                sum -= nums[start];
                start++;
            }
        }

        return count;
    }
};