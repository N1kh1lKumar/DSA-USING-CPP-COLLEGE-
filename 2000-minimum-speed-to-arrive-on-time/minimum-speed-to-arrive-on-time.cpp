class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low =1 , high = 10000000;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(dist, hour , mid)){
                ans =mid;
                high = mid -1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }


    bool isValid(vector<int> dist , double hour , int speed){
        double currHour = 0;

        for(int i =0; i<dist.size()-1; i++){
              currHour += ceil((double)dist[i] / speed);
        }

        currHour += (double)dist[dist.size() - 1] / speed;
        return currHour <= hour;
    }
};