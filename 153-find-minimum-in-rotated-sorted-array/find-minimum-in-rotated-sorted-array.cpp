class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // If the array is not rotated at all
        if (nums[low] <= nums[high]) {
            return nums[0];
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                return nums[mid];
            }

            // Check if mid+1 is the minimum element
            if (mid < n - 1 && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }

            if (nums[mid] > nums[low]) {
                low = mid + 1;
            } else {

                high = mid - 1;
            }
        }

        return nums[0];
    }
};
