class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = INT_MAX;
        int maximun = 0;
       for(int val: prices){
        if(val < minimum){
            minimum = val;
        }else{
            maximun = max(maximun, val-minimum);
        }
       }
       return maximun;
        
    }
};
