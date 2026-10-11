class Solution {
public:
    int sumOfSquares(vector<int>& arr) {
        int n = arr.size();

        int sumOfSpecial = 0;

        for(int i =0; i<n;i++){
            if(n % (i+1) == 0){
                sumOfSpecial += arr[i]*arr[i];
            }
        }
        return sumOfSpecial;        
    }
};