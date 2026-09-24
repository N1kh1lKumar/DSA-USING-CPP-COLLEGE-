class Solution {
public:
    bool isValid(vector<int>& piles, int h, int speed){
        long long currHour = 0;

        for(int pile : piles){

          if(pile % speed == 0){
            currHour += (pile/speed);
          }
          else{
              currHour += ((pile/speed)+1);
          }

        }
        return currHour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 , high = 0;
        for(int pile : piles){
            high = max(pile,high); 
        }

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(piles , h , mid)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};