class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;

        for(int x : nums){
            if(  count < 2 || nums[count-2] != x){
                nums[count] = x;
                count++;
            }
        }
        return count;
        
    }
};
