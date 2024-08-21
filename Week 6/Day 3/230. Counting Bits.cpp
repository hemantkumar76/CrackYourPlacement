class Solution {
public:
    vector<int> countBits(int n) {
        // Ek vector banate hain jisme hum store karenge har number ke binary representation mein kitne 1's hain
        vector<int> dp(n+1, 0);

        // Har number pe loop chalate hain
        for (int i = 1; i <= n; i++) {
            // Current number ke 1's ki count hoti hai uske immediate smaller even number ke 1's ki count + 1 agar wo number odd hai
            // Kyunki odd number ka binary representation hamesha end hota hai 1 se
            // Aur uske immediate smaller even number ka binary representation same hota hai uske alava last 1 ke
            dp[i] = dp[i/2] + i%2;
        }

        // Last mein hum vector return kar dete hain
        return dp;
    }
};
