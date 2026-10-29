class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = 0;
        int count = 0;
        int maxCount = 0;

        while (end < nums.size()) {

            if (nums[end] == 0) {
                count++;
            }

            while (count > k) {
                if (nums[start] == 0) {
                    count--;
                }
                start++;
            }
            maxCount = max(maxCount, end - start + 1);
            end++;
        }

        return maxCount;
    }
};
