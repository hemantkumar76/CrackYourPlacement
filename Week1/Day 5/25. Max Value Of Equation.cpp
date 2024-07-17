class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        // Initialize maxVal as the minimum possible value
        int maxVal = INT_MIN;
        
        // Deque to store pairs of (yi - xi) and xi
        deque<pair<int, int>> dq;
        
        for (auto& point : points) {
            int x = point[0], y = point[1];

            // Deque se purane elements ko remove karte hain jo x se zyada door hain
            while (!dq.empty() && x - dq.front().second > k) {
                dq.pop_front();
            }

            // Agar deque empty nahi hai, to maximum value update karte hain
            if (!dq.empty()) {
                maxVal = max(maxVal, y + x + dq.front().first);
            }

            // Current point ko deque mein insert karte hain aur old values ko remove karte hain jo useful nahi hain
            while (!dq.empty() && dq.back().first <= y - x) {
                dq.pop_back();
            }
            dq.push_back({y - x, x});
        }

        return maxVal;
    }
};
