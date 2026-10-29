class Solution {
public:
    int findComplement(int num) {

        if(num == 0) return 1;

        int binary[32], i = 0, ans = 0;
        long long power = 1;

        while (num > 0) {
            binary[i] = !(num % 2);
            num /= 2;
            i++;
        }

        for (int j = 0; j < i; j++) {
            ans += binary[j] * power;
            power *= 2;
        }

        return ans;
    }
};
