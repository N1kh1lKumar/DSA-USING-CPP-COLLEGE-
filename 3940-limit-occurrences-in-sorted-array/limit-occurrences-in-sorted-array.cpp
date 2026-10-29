class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;

        for (int num : nums) {
            if (ans.size() < k || ans[ans.size() - k] != num) {
                ans.push_back(num);
            }
        }

        return ans;
    }
}
;
