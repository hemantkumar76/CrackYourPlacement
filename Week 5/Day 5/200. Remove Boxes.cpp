class Solution {
public:
    int dp[100][100][100]; // DP array define kar rahe hain (100*100*100)

    int solve(int l, int r, int k, vector<int>& boxes) {
        if (l > r) return 0; // Agar left pointer right se aage nikal jaye, return 0

        if (dp[l][r][k] != -1) return dp[l][r][k]; // Agar DP mein pehle se result hai to wahi return karenge

        int originalR = r;
        int originalK = k;

        while (r > l && boxes[r] == boxes[r-1]) { // Continuously same color ke boxes count karenge
            r--;
            k++;
        }

        dp[l][originalR][originalK] = solve(l, r-1, 0, boxes) + (k+1)*(k+1); // Base case: current box sequence ko remove kar ke points calculate karenge

        for (int i = l; i < r; i++) { // Possible split points ke liye loop
            if (boxes[i] == boxes[r]) {
                dp[l][originalR][originalK] = max(dp[l][originalR][originalK], solve(l, i, k+1, boxes) + solve(i+1, r-1, 0, boxes)); // Max points calculate karenge
            }
        }

        return dp[l][originalR][originalK]; // Final result return karenge
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp)); // DP array ko -1 se initialize karenge
        return solve(0, boxes.size()-1, 0, boxes); // Recursion ko start karenge left se right tak
    }
};
