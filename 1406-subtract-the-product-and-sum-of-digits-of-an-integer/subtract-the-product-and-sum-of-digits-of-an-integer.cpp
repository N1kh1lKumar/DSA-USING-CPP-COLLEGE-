class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum =0;
        int product = 1;

        while(n){
            int rem = n%10;
            sum += rem;
            product *= rem;

            n = n/10;
        }

        int ans = product-sum;
        
        return ans;
    }
};