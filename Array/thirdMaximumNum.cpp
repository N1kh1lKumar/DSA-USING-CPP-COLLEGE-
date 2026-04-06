//Problem description:Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.
//Problem link : https://leetcode.com/problems/third-maximum-number/    (Problem no. 414)

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

        for (int num : nums) {
            if (num == first || num == second || num == third)
                continue;

            if (num > first) {
                third = second;
                second = first;
                first = num;
            }
            else if (num > second) {
                third = second;
                second = num;
            }
            else if (num > third) {
                third = num;
            }
        }

        return (third == LONG_MIN) ? first : third;
    }
};


int main(){
    Solution s;
    vector<int> nums = {2,2,3,1};
    int ans = s.thirdMax(nums);
    
    cout << ans << endl; 

    return 0;
}