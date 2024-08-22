class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // DP array banate hain with size amount+1 and initial value as amount+1
        std::vector<int> dp(amount + 1, amount + 1);
        
        // Zero amount banane ke liye zero coins chahiye
        dp[0] = 0;
        
        // Har amount ke liye loop chalate hain
        for (int i = 1; i <= amount; i++) {
            // Har coin ke liye loop chalate hain
            for (int j = 0; j < coins.size(); j++) {
                // Agar current coin se chota ya barabar amount hai toh
                if (coins[j] <= i) {
                    // Minimum coins ki value update karte hain
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
