class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        set<vector<int>> lol;
        long long sum;
        // nums ko sort karte hain
        sort(nums.begin(), nums.end());
        // Do outer loops chalate hain i aur j ke liye
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                int k = j + 1;
                int m = n - 1;
                // Inner while loop chalate hain k aur m ke liye
                while (k < m) {
                    // Sum calculate karte hain
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[k] + (long long)nums[m];
                    // Agar sum target se kam hai, toh k ko increment karte hain
                    if (sum < target) {
                        k++;
                    } else if (sum == target) {
                        // Agar sum target ke barabar hai, toh current combination ko 'lol' set mein daalte hain
                        lol.insert({nums[i], nums[j], nums[k], nums[m]});
                        k++;
                        m--;
                    } else {
                        // Agar sum target se jyada hai, toh m ko decrement karte hain
                        m--;
                    }
                }
            }
        }
        // 'lol' set ke har element ko 'res' vector mein daalte hain
        for (auto it : lol) {
            res.push_back(it);
        }
        // 'res' vector return karte hain
        return res;
    }
};
