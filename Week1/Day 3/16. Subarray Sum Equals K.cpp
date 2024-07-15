class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Ek map banate hain jisme hum store karenge cumulative sum aur uske occurrences
        unordered_map<int, int> cntr_sum;
        cntr_sum[0] = 1; // Zero sum pehle se hi hota hai
        int sum = 0;
        int count = 0;
        // Array ke har element ke liye, cumulative sum calculate karte hain
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // Agar 'sum - k' map mein exist karta hai, toh uske occurrences ko count mein add karte hain
            if (cntr_sum.count(sum - k)) {
                count += cntr_sum[sum - k];
            }
            // Current sum ki frequency ko update karte hain map mein
            cntr_sum[sum]++;
        }
        // Total count return karte hain
        return count;
    }
};
