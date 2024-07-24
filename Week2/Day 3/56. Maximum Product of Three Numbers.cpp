#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Sabse pehle hum array ko sort karenge
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // Ab hum do cases consider karenge
        // Case 1: Sabse bade 3 numbers ka product
        // Case 2: Agar negative numbers hain toh, sabse chote 2 numbers aur sabse bada number ka product
        // Kyunki negative * negative = positive
        // Hum in dono cases ka max return karenge
        return max(nums[n-1]*nums[n-2]*nums[n-3], nums[0]*nums[1]*nums[n-1]);
    }
};
