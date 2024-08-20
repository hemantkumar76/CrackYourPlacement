class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Deque banate hain
        vector<int> res; // Result vector banate hain
        for(int i = 0; i < nums.size(); i++) { // Array ke har element ke liye loop
            // Agar deque empty nahi hai aur deque ke front element ka index window se bahar hai, to hum us element ko deque se remove karte hain
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            // Jab tak deque empty nahi hota aur current element deque ke back element se bada hai, tab tak hum deque ke back element ko remove karte hain
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i); // Current element ko deque me add karte hain
            // Agar hum window ke end tak pahunch gaye hain, to hum deque ke front element ko result me add karte hain
            if(i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res; // Result return karte hain
    }
};
