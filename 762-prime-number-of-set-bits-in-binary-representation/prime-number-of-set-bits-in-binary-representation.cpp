#include <iostream>
using namespace std;

class Solution {
public:

    bool isprime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0) return false;
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int result = 0;

        for (int i = left; i <= right; i++) {
            int n = i;
            int binary[32];
            int k = 0;

            while (n > 0) {
                binary[k++] = n % 2;
                n /= 2;
            }

            int count1 = 0;

            for (int j = 0; j < k; j++) {
                if (binary[j] == 1)
                    count1++;
            }

            if (isprime(count1)) {
                result++;
            }
        }
        return result;
    }
};
