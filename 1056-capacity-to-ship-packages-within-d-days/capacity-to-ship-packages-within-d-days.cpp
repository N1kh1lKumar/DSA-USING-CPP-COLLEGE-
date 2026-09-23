class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low =0, high =0;

        for(int weight: weights){
            high += weight;
            low = max(low, weight);
        }
        
        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(weights,  days, mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }


    bool isValid(vector<int> weights , int days, int mid){
        int d =1, currElement = 0;

         for(int weight: weights){
            currElement += weight;

            if(currElement > mid){
                 currElement = weight;
                 d++;
            }
         }

         return d <= days;
    }
};