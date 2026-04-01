//Problem Description : Given an array nums of size n, return the majority element. 
//leetcode link: https://leetcode.com/problems/majority-element/description/ (Problrem no. 169)
#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0; 
        for(int val : nums){
            if(freq == 0) ans = val;
            if(val == ans) freq++;
            else freq--;
        }
        return ans;
    }
};

int main(){
   Solution S1;
   int n, major;
   
   vector<int> nums;
   cout << "Enter the size of array" << endl;
   cin >> n;
   cout << "Enter the array elements:" << endl;
   for(int i = 0; i<n; i++){ 
        int x;
        cin >> x;
        nums.push_back(x);
   }

    major = S1.majorityElement(nums);
    cout << "Major elements of the array is "<< major <<endl;
    return 0;
}