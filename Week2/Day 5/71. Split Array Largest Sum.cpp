#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Ye function check karta hai ki kya hum nums array ko k subarrays me divide kar sakte hain
    // jisme har subarray ka sum mid se zyada nahi hai
    bool isValid(vector<int>& nums, int k, int mid) {
        int count = 1; // Subarrays ka count
        int sum = 0; // Current subarray ka sum
        for (int num : nums) {
            // Agar current subarray ka sum mid se zyada ho jata hai
            // toh hum ek nayi subarray start karte hain
            if (sum + num > mid) {
                sum = num;
                count++;
                // Agar subarrays ka count k se zyada ho jata hai
                // toh hum false return karte hain
                if (count > k)
                    return false;
            } else {
                // Nahi toh hum current number ko current subarray me add karte hain
                sum += num;
            }
        }
        // Agar saari conditions satisfy ho jati hain toh hum true return karte hain
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        // Start point array ke sabse bade number se hota hai
        int start = *max_element(nums.begin(), nums.end());
        // End point array ke saare numbers ka sum hota hai
        int end = accumulate(nums.begin(), nums.end(), 0);
        // Binary search start karte hain
        while (start < end) {
            // Mid point find karte hain
            int mid = start + (end - start) / 2;
            // Agar hum nums array ko k subarrays me divide kar sakte hain
            // jisme har subarray ka sum mid se zyada nahi hai
            // toh hum end point ko mid se set karte hain
            if (isValid(nums, k, mid))
                end = mid;
            else
                // Nahi toh hum start point ko mid + 1 se set karte hain
                start = mid + 1;
        }
        // Last me, start point return karte hain jo minimized largest sum hota hai
        return start;
    }
};
