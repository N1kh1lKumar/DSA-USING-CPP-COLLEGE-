class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, wsum = 0;
        int length = INT_MAX;

        for (; end < nums.size(); end++) {
            wsum += nums[end];

            while (wsum >= target) {
                length = min(length, end - start + 1);

                wsum -= nums[start];
                start++;
            }
        }
        return (length > nums.size())? 0 : length;
    }
};