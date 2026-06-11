//problem description: Find First and Last Position of Element in Sorted Array (Problem no. = 34)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> nums, int n,int  target){
        int st =0, end = n-1;
        int ans = n;

        while(st<=end){
            int mid = st + (end-st)/2;

            if(nums[mid] >= target){
                ans = min(ans, mid);
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }

    int upperBound(vector<int> nums, int n,int  target){
        int st =0, end = n-1;
        int ans = n;

        while(st<=end){
            int mid = st + (end-st)/2;

            if(nums[mid] > target){
                ans = min(ans, mid);
                end = mid-1;
            }
            else{
                st = mid+1;
            }
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int n= nums.size();

        int lb = lowerBound(nums,  n,  target);
        int ub = upperBound(nums,  n,  target);

      

        if(lb == ub) return {-1, -1};
        else return {lb, ub-1};
    
    }
};

