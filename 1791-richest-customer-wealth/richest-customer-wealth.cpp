class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maximumWealth = INT_MIN;
        for( auto customer: accounts){
            int wealth = 0;
            for(auto banks: customer){
                    wealth += banks;
            }

            maximumWealth = max(maximumWealth , wealth);
        }
    
    return maximumWealth;
    }

};