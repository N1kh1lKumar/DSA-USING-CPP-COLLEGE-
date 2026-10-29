class Solution {
public:
    int digitFrequencyScore(int n) {
        int ans =0;
        
        while(n>0){
          int rem = n %10;
           ans += rem;
           n = n/10;
        }        
    
      return ans;
    }
    
};
