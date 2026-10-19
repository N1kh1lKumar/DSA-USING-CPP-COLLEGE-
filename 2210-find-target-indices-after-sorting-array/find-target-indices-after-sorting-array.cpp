class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
      int smallerCount = 0;
      int equalCount = 0;
      for(int num : nums){
        if(num < target){
            smallerCount++;
        }
        else if(num == target){
            equalCount++;
        }
      }

    vector<int> ans;
      while(equalCount--){
        ans.push_back(smallerCount++);
      }
      return ans;   
    }
};