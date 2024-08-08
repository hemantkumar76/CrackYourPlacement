class Solution {
public:
    int numTrees(int n) {
        // Ek vector banate hain jisme hum store karenge ki i nodes ke liye kitne unique BST possible hain
        vector<int> dp(n + 1, 0);

        // 0 nodes ya 1 node ke liye sirf 1 unique BST possible hai
        dp[0] = 1;
        dp[1] = 1;

        // i nodes ke liye unique BST calculate karte hain
        for (int i = 2; i <= n; i++) {
            // j ko root node maan ke left aur right subtrees ke liye unique BST calculate karte hain
            for (int j = 1; j <= i; j++) {
                // Left subtree mein j - 1 nodes honge aur right subtree mein i - j nodes honge
                // Dono subtrees ke liye unique BST ki count multiply kar ke dp[i] mein add karte hain
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        // n nodes ke liye unique BST ki count return karte hain
        return dp[n];
    }
};
