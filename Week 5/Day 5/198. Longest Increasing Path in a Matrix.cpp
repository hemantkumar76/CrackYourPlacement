class Solution {
    vector<vector<int>> dp; // Memoization ke liye dp array define kar rahe hain
    int dr[4] = {-1,0,1,0}; // Row direction ke liye offsets define kar rahe hain
    int dc[4] = {0,-1,0,1}; // Column direction ke liye offsets define kar rahe hain
public:
    int dfs(int row, int col, vector<vector<int>>& mat) {
        int m = mat.size(); // Matrix ke rows ka size le rahe hain
        int n = mat[0].size(); // Matrix ke columns ka size le rahe hain

        if (dp[row][col] != 0) { // Agar dp mein pehle se value hai, to wahi return karenge
            return dp[row][col];
        }

        int maxLength = 1; // Initial maxLength 1 set kar rahe hain
        
        for (int k = 0; k < 4; k++) { // 4 possible directions ke liye loop
            int nr = row + dr[k]; // New row calculate kar rahe hain
            int nc = col + dc[k]; // New column calculate kar rahe hain
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] > mat[row][col]) { // Valid position check kar rahe hain aur agar adjacent cell ki value zyada hai
                maxLength = max(maxLength, 1 + dfs(nr, nc, mat)); // DFS call kar ke maxLength update kar rahe hain
            }
        }

        return dp[row][col] = maxLength; // Current cell ka maxLength dp mein store karke return kar rahe hain
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(); // Matrix ke rows ka size le rahe hain
        int n = matrix[0].size(); // Matrix ke columns ka size le rahe hain

        dp = vector<vector<int>>(m, vector<int>(n, 0)); // DP array initialize kar rahe hain with 0

        int maxPath = 1; // Initial maxPath 1 set kar rahe hain
        for (int i = 0; i < m; i++) { // Har row ke liye
            for (int j = 0; j < n; j++) { // Har column ke liye
                maxPath = max(maxPath, dfs(i, j, matrix)); // DFS call kar ke maxPath update kar rahe hain
            }
        }

        return maxPath; // Longest increasing path length return kar rahe hain
    }
};
