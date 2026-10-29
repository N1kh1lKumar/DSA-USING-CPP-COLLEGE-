class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            
            if (rev > numeric_limits<int>::max() / 10 ||
                (rev == numeric_limits<int>::max() / 10 && digit > 7))
                return 0;

            if (rev < numeric_limits<int>::min() / 10 ||
                (rev == numeric_limits<int>::min() / 10 && digit < -8))
                return 0;

            rev = rev * 10 + digit;
        }
        return rev;
    }
    bool isPalindrome(int x) {

        if (x<0){
            return false;
        }
        else{ 
        int rev = reverse(x);    

        if(rev == x){
            return true;
        }
        else{
            return false;
        }
        }
    }
};
