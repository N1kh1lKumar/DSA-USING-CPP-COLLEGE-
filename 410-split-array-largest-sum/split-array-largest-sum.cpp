class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;

        for( int num : nums){
            low = max(low , num);
            high += num;
        }

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(nums, k , mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }


    bool isValid(vector<int> nums, int k , int sum){
        int currSum  = 0 , split=1;

        for(int num : nums){
            currSum += num;

            if(currSum > sum){
                split++;
                currSum = num;
            }
        }

        return split <= k;
    }
};