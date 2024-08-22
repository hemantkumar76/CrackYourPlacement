class Solution {
public:
    int numDecodings(std::string s) {
        // Agar pehla character '0' hai toh decode karne ke ways 0 honge
        if (s[0] == '0') return 0;
        
        // DP array banate hain with size s.length() + 1 and initial value as 0
        std::vector<int> dp(s.length() + 1, 0);
        
        // Base cases set karte hain
        dp[0] = 1;
        dp[1] = 1;
        
        // 2 se leke s.length() tak loop chalate hain
        for (int i = 2; i <= s.length(); i++) {
            // Agar current character '0' se bada hai toh usko single digit number maan kar decode kar sakte hain
            if (s[i - 1] > '0') dp[i] = dp[i - 1];
            
            // Agar last two digits 10 se 26 ke beech mein hain toh unko double digit number maan kar decode kar sakte hain
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) dp[i] += dp[i - 2];
        }
        
        // Last cell of DP array contains the total number of ways to decode the string
        return dp[s.length()];
    }
};
