class Solution {
public:
    int lowerBound(vector<int> num, int n, int target) {
        int low = 0, high = n-1;

        while(low<= high){
            int mid = low + (high - low)/2;

            if(num[mid] >= target) {
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low;
    }

    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int index = lowerBound(nums, n, target);
        return index;
    }
}; 