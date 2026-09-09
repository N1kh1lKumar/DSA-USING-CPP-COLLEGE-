class Solution {
public:
    long long countCommas(long long n) {
        long long total_comma = 0;
        long long count = 1000;

        while (n >= count) {

            total_comma += (n - count + 1);
            if (count > 1000000000000LL) {
                break;
            }
            count *= 1000;
        }

        return total_comma;
    }
};