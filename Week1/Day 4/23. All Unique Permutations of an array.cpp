class Solution {
  public:
    void permute(vector<int> &nums, int l, set<vector<int>> &s) {
        // Base case: agar 'l' 'nums' ke size se barabar hai
        if (l == nums.size()) {
            // Toh 'nums' ko 's' me daalte hain
            s.insert(nums);
        }
        // 'nums' ke har element ke liye
        for (int i = l; i < nums.size(); i++) {
            // 'nums[l]' aur 'nums[i]' ko swap karte hain
            swap(nums[l], nums[i]);
            // Recursively 'nums' ke next elements ke permutations generate karte hain
            permute(nums, l + 1, s);
            // 'nums[l]' aur 'nums[i]' ko wapas swap karte hain toh original array restore karne ke liye
            swap(nums[l], nums[i]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // 'arr' ko sort karte hain
        sort(arr.begin(), arr.end());
        // 's' ko initialise karte hain
        set<vector<int>> s;
        // 'permute' function ko call karte hain
        permute(arr, 0, s);
        // 's' ke elements ko 'res' me daalte hain
        vector<vector<int>> res(s.begin(), s.end());
        // 'res' return karte hain
        return res;
    }
};
