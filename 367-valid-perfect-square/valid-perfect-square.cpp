class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 0 || num ==1) return true;

        int low = 2 , high = num/2;
        while(low <= high){
            int mid = low + (high -low) /2;
            if((long long)mid * mid == num){
                return true;
            }
            else if((long long) mid* mid < num){
                low = mid+1;
            }else{
                high = mid -1;
            }
        }

        return false;
    }
};