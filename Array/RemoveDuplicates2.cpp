//Problem description: Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice.
// The relative order of the elements should be kept the same.

//problrem link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;

        for(int x : nums){
            if(  count < 2 || nums[count-2] != x){
                nums[count] = x;
                count++;
            }
        }
        return count;
        
    }
};