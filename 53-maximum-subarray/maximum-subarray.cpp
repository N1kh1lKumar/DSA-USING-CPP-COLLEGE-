class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = INT_MIN, curr = 0;
        for(int val : nums){
            curr += val;
            maxsum = max(maxsum, curr);
            if(curr <0) curr = 0;
        }
        return maxsum;}
};
