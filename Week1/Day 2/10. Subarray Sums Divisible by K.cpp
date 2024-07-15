class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // count array aur prefix sum ko initialise karte hain
        vector<int> count(k, 0);
        count[0] = 1;
        int prefixSum = 0, res = 0;

        for (int i = 0; i < nums.size(); i++) {
            // prefix sum calculate karte hain aur negative values handle karte hain
            prefixSum = (prefixSum + nums[i] % k + k) % k;

            // result mein count of subarrays with the same prefix sum ko increment karte hain
            res += count[prefixSum]++;

            // Note: count[prefixSum]++ is equivalent to:
            // res += count[prefixSum];
            // count[prefixSum] = count[prefixSum] + 1;
        }

        // k se divisible total number of subarrays return karte hain
        return res;
    }
};
