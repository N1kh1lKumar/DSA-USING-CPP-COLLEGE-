class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        int row = 0;
        int col = m - 1;
        
        while (row < n && col >= 0) {
            if (grid[row][col] < 0) {
                count += (n - row);
                col--;
            } else {
                row++;
            }
        }
        
        return count;
    }
};
