class Solution {
public:
    int numDistinct(string s, string t) {
        // dp array banate hain, jiska size (s.length() + 1) x (t.length() + 1) hoga
        vector<vector<unsigned int>> dp(s.length() + 1, vector<unsigned int>(t.length() + 1, 0));

        // Pehle row ko 1 se fill karte hain, kyunki empty string ka ek hi subsequence hota hai
        for(int i = 0; i <= s.length(); i++)
            dp[i][0] = 1;

        // dp array ko fill karte hain
        for(int i = 1; i <= s.length(); i++) {
            for(int j = 1; j <= t.length(); j++) {
                // Agar s aur t ke current characters match hote hain, toh hum s aur t dono ko ek character chhote karke check karte hain
                // ya phir sirf s ko ek character chhote karke check karte hain
                if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                // Agar match nahi hote, toh sirf s ko ek character chhote karke check karte hain
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        // dp array ke last element ko return karte hain, jo final answer hoga
        return dp[s.length()][t.length()];
    }
};
