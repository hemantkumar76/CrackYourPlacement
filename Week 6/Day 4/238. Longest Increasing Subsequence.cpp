#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        // DP array banate hain with size nums.size() and initial value as 1
        std::vector<int> dp(nums.size(), 1);
        
        // Maximum length of LIS
        int max_length = 1;
        
        // nums ke har element ke liye loop chalate hain
        for (int i = 1; i < nums.size(); i++) {
            // i se pehle ke har element ke liye loop chalate hain
            for (int j = 0; j < i; j++) {
                // Agar nums[j] < nums[i] hai toh
                if (nums[j] < nums[i]) {
                    // DP[i] ko update karte hain max(DP[i], DP[j] + 1) se
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            // Maximum length update karte hain
            max_length = std::max(max_length, dp[i]);
        }
        
        // Return maximum length
        return max_length;
    }
};
