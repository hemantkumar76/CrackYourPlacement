class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Ek 3D DP array banate hain jisme hum store karenge ki kisi specific number of 0's aur 1's ke saath maximum kitne strings select kar sakte hain
        vector<vector<vector<int>>> dp(strs.size()+1, vector<vector<int>>(m+1, vector<int>(n+1, 0)));

        // Har string pe loop chalate hain
        for (int i = 1; i <= strs.size(); i++) {
            // Har string ke 0's aur 1's count karte hain
            int zeros = count(strs[i-1].begin(), strs[i-1].end(), '0');
            int ones = strs[i-1].size() - zeros;

            // Har possible number of 0's aur 1's pe loop chalate hain
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    // Agar hum current string ko select nahi karte toh DP value same rahegi
                    dp[i][j][k] = dp[i-1][j][k];

                    // Agar hum current string ko select kar sakte hain (i.e., usme 0's aur 1's humare limit se kam ya barabar hain)
                    // toh hum max value update karte hain select karne ke baad ki
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-zeros][k-ones] + 1);
                    }
                }
            }
        }

        // Last mein hum maximum number of strings return kar dete hain jo hum select kar sakte hain
        return dp[strs.size()][m][n];
    }
};
