class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
     
        int n = nums.size();

        vector<int> freq(n + 2, 0);

        for(int i = 0; i < n; i++) {

            if(nums[i] <= n) {
                freq[nums[i]]++;
            }
        }

        vector<int> ans;

        int i = 0;

        while(i < n) {

            int mex = 0;

            while(freq[mex] > 0) {
                mex++;
            }

            if(mex == 0) {

                ans.push_back(0);

                if(nums[i] <= n) {
                    freq[nums[i]]--;
                }

                i++;

            } else {

                vector<int> vis(mex, 0);

                int need = mex;

                int j = i;

                while(j < n && need > 0) {

                    if(nums[j] < mex && vis[nums[j]] == 0) {

                        vis[nums[j]] = 1;
                        need--;
                    }

                    j++;
                }

                ans.push_back(mex);

                for(int k = i; k < j; k++) {

                    if(nums[k] <= n) {
                        freq[nums[k]]--;
                    }
                }

                i = j;
            }
        }

        return ans;
   
    }
};
