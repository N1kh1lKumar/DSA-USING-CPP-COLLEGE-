
class Solution {
public:
   vector<int> rearrangeArray(vector<int>& nums) {
        std::map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        vector<int> ans;
        ans.reserve(nums.size()); 

       
        while (!counts.empty()) {
            
            for (auto it = counts.begin(); it != counts.end(); ) {
                ans.push_back(it->first); 
                it->second--;         

              
                if (it->second == 0) {
                    it = counts.erase(it);
                } else {
                    ++it;
                }
            }
        }

        return ans;
    }
};
