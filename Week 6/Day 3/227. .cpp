class Solution {
public:
    int climbStairs(int n) {
        // Ek array banate hain jisme hum har step pe kitne tarike se pahunch sakte hain wo store karenge
        int dp[n+1]; 

        // 0th step pe pahunchne ke sirf 1 tarika hota hai wahi pe toh hum start karte hain
        dp[0]=1; 

        // 1st step pe pahunchne ke bhi sirf 1 tarika hota hai ya toh direct jump maar ke
        dp[1]=1; 

        // Ab baaki steps ke liye loop chalate hain
        for(int i=2;i<=n;i++){
            // i-th step pe pahunchne ke tarike hote hain i-1th step pe pahunchne ke tarike + i-2th step pe pahunchne ke tarike
            // Kyunki hum ya toh ek step peeche se jump maar ke pahunch sakte hain ya do step peeche se
            dp[i]=dp[i-1]+dp[i-2];
        }

        // Last mein hum n-th step pe pahunchne ke total tarike return kar dete hain
        return dp[n];
    }
};
