/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 * public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray& mountainArr) {
        int low = 0;
        int high = mountainArr.length() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1; 
            } else {
                high = mid;    // Peak is at mid or to the left
            }
        }
        return low; // low and high will  at the peak index
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int peakIndex = findPeak(mountainArr);
        
        // 1. Search in the left (increasing) side
        int low = 0, high = peakIndex;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        // 2. Search in the right (decreasing) side
        low = peakIndex + 1;
        high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) { // Elements decrease as index increases
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};
