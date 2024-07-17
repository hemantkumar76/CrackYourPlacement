class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // Stack to store index aur height ka pair
        heights.push_back(0); // Heights ke end mein zero add karte hain to ensure last rectangle bhi process ho jaye
        int maxArea = 0; // Maximum area ko store karne ke liye variable
        
        // Heights array ko iterate karte hain
        for (int i = 0; i < heights.size(); i++) {
            int start = i; // Current index ko start variable mein store karte hain
            
            // Jab tak stack empty nahi hota aur stack ka top height current height se bada hota hai
            while (!st.empty() && st.top().second > heights[i]) {
                auto [idx, height] = st.top(); // Stack se top element ko nikalte hain
                st.pop();
                // Max area ko calculate karte hain
                maxArea = max(maxArea, height * (i - idx));
                start = idx; // Start ko update karte hain
            }
            
            // Current index aur height ko stack mein push karte hain
            st.push({start, heights[i]});
        }
        
        return maxArea; // Maximum area return karte hain
    }
};
