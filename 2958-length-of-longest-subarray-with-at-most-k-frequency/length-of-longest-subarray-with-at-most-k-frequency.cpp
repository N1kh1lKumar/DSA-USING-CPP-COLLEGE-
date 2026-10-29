class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0;
        unordered_map<int, int> freq;
        int maxLength = 0;
        for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;

            while (freq[nums[end]] > k) {
                freq[nums[start++]]--;
            }
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
