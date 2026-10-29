class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int left = 0;
        int right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Calculate how many numbers are missing before the current index
            int missing = arr[mid] - (mid + 1);
            
            if (missing < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // The kth missing number is always left + k after the search terminates
        return left + k;
    }
};
