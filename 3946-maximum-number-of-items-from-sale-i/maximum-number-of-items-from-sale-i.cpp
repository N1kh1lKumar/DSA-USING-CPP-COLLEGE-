class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
         int n = items.size();
        vector<int> gain(n);

        int mn = INT_MAX;

        for(int i = 0; i < n; i++) {

            int cnt = 1;

            for(int j = 0; j < n; j++) {

                if(i != j && items[j][0] % items[i][0] == 0) {
                    cnt++;
                }
            }

            gain[i] = cnt;
            mn = min(mn, items[i][1]);
        }

        vector<int> dp(budget + 1, 0);

        for(int i = 0; i < n; i++) {

            int cost = items[i][1];

            for(int j = budget; j >= cost; j--) {

                dp[j] = max(dp[j], dp[j - cost] + gain[i]);
            }
        }

        int ans = budget / mn;

        for(int i = 0; i <= budget; i++) {

            ans = max(ans, dp[i] + (budget - i) / mn);
        }

        return ans;
 
    }
};
