class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int start = 0, end =0, sum=0;
        double maxAverage = -DBL_MAX;

        for(;end<nums.size();end++){
            sum += nums[end];

            if(end - start +1  == k){
                maxAverage = max( maxAverage , (double(sum)/ k));
                sum -= nums[start];
                start++;
            }
        } 

        return maxAverage;
    }
};