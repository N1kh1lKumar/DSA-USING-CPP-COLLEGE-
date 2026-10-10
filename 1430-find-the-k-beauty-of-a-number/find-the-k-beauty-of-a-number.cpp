
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int temp = num;
        long long divisor = 1;

        for (int i = 0; i < k; i++) {
            divisor *= 10;
        }

        int x = num % divisor;
        int count = 0;

        while (temp >= divisor / 10) {
            if (x != 0 && num % x == 0) {
                count++;
            }

            temp /= 10;
            if (temp < divisor / 10) break;

            x = temp % divisor;
        }

        return count;
    }
};
