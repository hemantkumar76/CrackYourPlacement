class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        // Grid ke dimensions nikal karte hai
        int m = grid.size();
        int n = grid[0].size();
        
        // DP table bana karte hai with same dimensions as grid
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        
        // DP table ki first cell ko grid ke first cell se initialize kar karte hai
        dp[0][0] = grid[0][0];
        
        // Pehle row ke liye path sum calculate kar karte hai
        for(int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        // Pehle column ke liye path sum calculate kar karte hai
        for(int i = 1; i < m; i++) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        // Baki cells ke liye minimum path sum calculate kar karte hai
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                // Minimum path sum is the current cell's value plus the minimum of the cell above and to the left
                dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};
