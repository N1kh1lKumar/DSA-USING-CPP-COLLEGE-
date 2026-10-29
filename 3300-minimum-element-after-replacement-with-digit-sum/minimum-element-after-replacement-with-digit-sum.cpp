class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            int temp = nums[i];
            int rem = 0, sum =0;
            while(temp>0){
                rem = temp%10;
                sum += rem;
                temp /= 10;                
            }
            mn = min(sum, mn);
        }
        

        return mn;
    }
};
