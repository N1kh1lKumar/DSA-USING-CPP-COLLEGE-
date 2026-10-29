class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        
        // Step 1: Perform the cyclic left shifts on each row
        vector<vector<int>> midGrid(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            // Normalize shift amount to prevent negative indices or excessive looping
            int shift = (rowShift[i] % n + n) % n;
            for (int j = 0; j < n; ++j) {
                int newCol = (j - shift + n) % n;
                midGrid[i][newCol] = grid[i][j];
            }
        }
        
        // Step 2: Perform the cyclic upward shifts on each column
        vector<vector<int>> resultGrid(n, vector<int>(n));
        for (int j = 0; j < n; ++j) {
            // Normalize shift amount
            int shift = (colShift[j] % n + n) % n;
            for (int i = 0; i < n; ++i) {
                int newRow = (i - shift + n) % n;
                resultGrid[newRow][j] = midGrid[i][j];
            }
        }
        
        return resultGrid;
    }
};
