#include <vector>
#include <algorithm>

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        // DP array banate hain with size nums1.length() + 1 and nums2.length() + 1 and initial value as 0
        std::vector<std::vector<int>> dp(nums1.size() + 1, std::vector<int>(nums2.size() + 1, 0));
        
        // Maximum length of repeated subarray
        int max_length = 0;
        
        // nums1 ke har element ke liye loop chalate hain
        for (int i = nums1.size() - 1; i >= 0; i--) {
            // nums2 ke har element ke liye loop chalate hain
            for (int j = nums2.size() - 1; j >= 0; j--) {
                // Agar nums1[i] aur nums2[j] same hain toh
                if (nums1[i] == nums2[j]) {
                    // DP[i][j] ko update karte hain DP[i+1][j+1] + 1 se
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    // Maximum length update karte hain
                    max_length = std::max(max_length, dp[i][j]);
                }
            }
        }
        return max_length;
    }
};
