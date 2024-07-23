class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Array ko sort karte hain
        sort(nums.begin(), nums.end());
        
        // Median ko target banate hain
        int target = nums[nums.size() / 2];
        
        // Minimum moves calculate karte hain
        int moves_hoga = 0;
        for (int num : nums) {
            // Har number ke liye, uska distance target se add karte hain
            moves_hoga += abs(num - target);
        }
        
        // Minimum moves return karte hain
        return moves_hoga;
    }
};
