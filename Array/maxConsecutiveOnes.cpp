//problrem Description: Given a binary array nums, return the maximum number of consecutive 1's in the array.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() ==  1 && nums[0] == 0) return 0;

        int freq = 0;
        int mx = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 1){
                freq++;
                mx = max(mx, freq);

            }
            else{
                freq = 0;
            }

        }
      return max(mx,freq);
    }
};