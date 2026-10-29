class Solution {
public:
    int hammingWeight(int n) {
          int count1 = 0;

        for (int i = 0; i <= n; i++) {
           
            int binary[32];
            int k = 0;

            while (n > 0) {
                binary[k++] = n % 2;
                n /= 2;
            }

            

            for (int j = 0; j < k; j++) {
                if (binary[j] == 1)
                    count1++;
            }
        }  
            return count1;
  
    }
};
