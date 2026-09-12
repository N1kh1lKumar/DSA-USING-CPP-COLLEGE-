class Solution {
public:
    int countPartitions(vector<int>& nums) {
         int n = nums.size();
        int total_sum = 0;
        
        for (int num : nums) {
            total_sum += num;
        }
        
        return (total_sum % 2 == 0) ? (n - 1) : 0;
    }
};