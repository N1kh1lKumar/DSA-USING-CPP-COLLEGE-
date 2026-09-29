class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = INT_MAX;
        int high = INT_MIN;

        for (int day : bloomDay) {
            low = min(low, day);
            high = max(high, day);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = 0;
            int bouquets = 0;

            for (int day : bloomDay) {
                if (day <= mid) {
                    count++;
                    if (count == k) {
                        bouquets++;
                        count = 0;
                    }
                } else {
                    count = 0;
                }
            }

            if (bouquets >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};