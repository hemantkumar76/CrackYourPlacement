class Solution {
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k) {
        // Ek stack banate hain
        stack<int> st;
        int n = nums.size();

        // Har number ke liye
        for (int i = 0; i < n; ++i) {
            // Jab tak stack me kuch hai, aur stack ke top pe jo number hai woh current number se bada hai, aur stack se numbers hata kar bhi hum k size ka subsequence bana sakte hain
            while (!st.empty() && st.top() > nums[i] && st.size() - 1 + n - i >= k) {
                // Stack ke top wale number ko hata dete hain
                st.pop();
            }

            // Agar stack ka size k se chota hai toh current number ko stack me daal dete hain
            if (st.size() < k) {
                st.push(nums[i]);
            }
        }

        // Stack me jo numbers hain unhe ek vector me daalte hain
        vector<int> result_hoga(k);
        for (int i = k - 1; i >= 0; i--) {
            result_hoga[i] = st.top();
            st.pop();
        }
        return result_hoga;
    }
};
