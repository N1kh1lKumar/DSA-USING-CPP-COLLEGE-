class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> nums3;
        double ans;
        int i =0, j=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                nums3.push_back(nums1[i++]);
            }
            else if(nums1[i]> nums2[j]){
                nums3.push_back(nums2[j++]);
            }
            else{
                nums3.push_back(nums1[i++]);
                nums3.push_back(nums2[j++]);
            }
        }

        if(i==n){
            while(j<m){
                   nums3.push_back(nums2[j++]);
            }
        }

        if(j==m){
            while(i<n){ 
         nums3.push_back(nums1[i++]);
        }
        }

        int p = m+n;

        if(p%2==0){
            int mid = p/2;
            ans = double(nums3[mid]+nums3[mid-1])/2;
        }else{
            int mid = p/2+1;
            ans = double(nums3[mid-1]);
        }
        return ans;
    }
};