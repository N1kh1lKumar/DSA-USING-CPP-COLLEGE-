class Solution {
public:
    string triangleType(vector<int>& nums) {
      int a = nums[0], b = nums[1], c = nums[2];

        int total_sum = a + b + c;
        int max_side = max({a, b, c});
        
        if (total_sum - max_side <= max_side) {
            return "none";
        }

        if (a == b && b == c) {
            return "equilateral";
        }
        
        if (a == b || b == c || a == c) {
            return "isosceles";
        }

        return "scalene";
    }
};