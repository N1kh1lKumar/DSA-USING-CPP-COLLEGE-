class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]) , arr2.push_back(nums[1]);
        int arr1_last = nums[0] , arr2_last = nums[1];

        for(int i =2; i<nums.size(); i++){
            if(arr1_last > arr2_last){
                arr1.push_back(nums[i]);
                arr1_last = nums[i];
            }else{
                arr2.push_back(nums[i]);
                arr2_last = nums[i];
            }
        }

        for(int x: arr2){
            arr1.push_back(x);
        }

        return arr1;
    }
};