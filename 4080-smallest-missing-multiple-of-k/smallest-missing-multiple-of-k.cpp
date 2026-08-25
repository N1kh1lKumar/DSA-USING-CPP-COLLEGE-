class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> exist(101, false);

        for (int x : nums) {
            if (x <= 100) {
                exist[x] = true;
            }
        }

        int temp = k;
        for (int i = 0; i < exist.size(); i++) {

            while(temp <= 100){
            if (!exist[temp]) {
                return temp;
            }

            temp += k;
        }
        }
        return temp;
    }
};