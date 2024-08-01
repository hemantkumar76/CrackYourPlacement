class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Ek stack banate hain jisme hum nums2 ke elements dalenge
        stack<int> s;
        // Ek map banate hain jisme hum nums2 ke elements aur unke next greater elements store karenge
        unordered_map<int, int> m;

        // nums2 ke har element ke liye
        for (int num : nums2) {
            // Jab tak stack khali nahi hota aur stack ke top pe element num se chota hai
            while (!s.empty() && s.top() < num) {
                // Stack ke top element ka next greater element num hai, isko map me store karte hain
                m[s.top()] = num;
                // Stack ke top element ko hata dete hain kyunki uska next greater element mil gaya
                s.pop();
            }
            // num ko stack me dalte hain
            s.push(num);
        }

        // nums1 ke har element ke liye
        for (int i = 0; i < nums1.size(); i++) {
            // Agar nums1[i] ka next greater element map me hai to use nums1[i] me replace karte hain
            // Nahi to nums1[i] me -1 dalte hain
            nums1[i] = m.count(nums1[i]) ? m[nums1[i]] : -1;
        }

        // Updated nums1 return karte hain
        return nums1;
    }
};
