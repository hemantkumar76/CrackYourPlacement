class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> map; // Ek unordered_map banate hain jisme hum numbers ko store karenge
        for (int i = 0; i < nums.size(); i++) { // Har ek number ke liye loop chalate hain
            if (map.find(nums[i]) != map.end()) { // Agar number pehle se map mein hai, toh woh duplicate hai
                return nums[i]; // Duplicate number return kar dete hain
            } else
                map[nums[i]] = 1; // Agar number pehle se map mein nahi hai, toh usko map mein add kar dete hain
        }
        return 0; // Agar koi duplicate number nahi mila, toh 0 return kar dete hain
    }
};
