#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {

        int binary[32], i = 0;
       
         while (n > 0) 
        {
            binary[i] = n % 2;
            n = n / 2;
            i++;
        }

        for (int j = i - 1; j > 0; j--) 
        {
            if (binary[j] == binary[j - 1]) 
            {
                return false;
            }
           
        }
         return true;
    }
   
};
