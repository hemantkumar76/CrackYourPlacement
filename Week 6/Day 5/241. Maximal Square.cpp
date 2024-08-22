class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix) {
        // Rows aur columns ki count nikalte hain
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // DP array banate hain with size rows x cols and initial value as 0
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
        
        // Maximum size of square
        int max_size = 0;
        
        // Matrix ke har cell ke liye loop chalate hain
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Agar cell top row ya left column mein hai toh
                if (i == 0 || j == 0) {
                    // DP[i][j] ko update karte hain matrix[i][j] se
                    dp[i][j] = matrix[i][j] - '0';
                }
                // Agar cell 1 hai toh
                else if (matrix[i][j] == '1') {
                    // DP[i][j] ko update karte hain minimum of its top, left, and top-left neighbors + 1 se
                    dp[i][j] = std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                }
                // Maximum size ko update karte hain DP[i][j] se
                max_size = std::max(max_size, dp[i][j]);
            }
        }
        
        // Return the area of the maximal square
        return max_size * max_size;
    }
};
