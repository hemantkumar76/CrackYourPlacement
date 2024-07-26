#include<bits/stdc++.h>
using namespace std;

// Fenwick Tree ya Binary Indexed Tree (BIT) class
class FenwickTree {
    vector<int> BIT; // BIT array
    int n; // Size of BIT array
public:
    // Constructor
    FenwickTree(int n) {
        this->n = n + 1; // Size set karte hain
        BIT = vector<int>(this->n, 0); // BIT array ko initialize karte hain
    }

    // Update function, jo BIT array me value add karta hai
    void update(int idx, int value) {
        for (; idx < n; idx += idx & -idx)
            BIT[idx] += value;
    }

    // Query function, jo BIT array se sum find karta hai
    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += BIT[idx];
        return sum;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // nums array ko sorted order me ek set me store karte hain
        set<int> sorted(nums.begin(), nums.end());
        // Har number ki rank store karne ke liye ek map banate hain
        unordered_map<int, int> ranks;
        int rank = 0;
        // Har number ki rank find karte hain
        for (const int num : sorted)
            ranks[num] = ++rank;

        // Fenwick Tree banate hain
        FenwickTree tree(ranks.size());
        // Counts array banate hain
        vector<int> counts(nums.size());
        // nums array ko reverse order me traverse karte hain
        for (int i = nums.size() - 1; i >= 0; --i) {
            // Har number se chhote ya barabar numbers ka count find karte hain
            counts[i] = tree.query(ranks[nums[i]] - 1);
            // Current number ko BIT me add karte hain
            tree.update(ranks[nums[i]], 1);
        }
        // Last me, counts array return karte hain
        return counts;
    }
};
