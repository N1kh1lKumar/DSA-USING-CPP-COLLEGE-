class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(vector<int> row : grid){

            int low = 0, high = row.size()-1;
            while(low <= high){
                int mid = low+ (high  - low)/2;

                if(row[mid] <0){
                  high = mid-1;
                }
                else{
                   low = mid+1;
                }

            }
            count += (row.size() - low);
        }
        return count;
    }
};