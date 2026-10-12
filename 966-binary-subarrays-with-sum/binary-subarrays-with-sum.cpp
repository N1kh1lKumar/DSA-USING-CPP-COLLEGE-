class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal - 1);
    }

    int atmost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        
        int start = 0, end = 0;
        int count = 0;
        int sum = 0;

        for (; end < nums.size(); end++) {
            sum += nums[end];

            while (sum > goal) {
                sum -= nums[start];
                start++;
            }
             count += end - start + 1;
        }
        return count;
    }
};