class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int abs_diff = INT_MAX;

        for(int i =0; i<arr.size()-1; i++){
            abs_diff = min(abs_diff, arr[i+1] - arr[i]);
        }

        vector<vector<int>> ans;
        for(int i =0; i<arr.size()-1; i++){
            if(abs(arr[i+1] - arr[i]) == abs_diff){
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};