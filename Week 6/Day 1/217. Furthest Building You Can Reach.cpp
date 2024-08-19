class Solution {
public:
    int furthestBuilding(std::vector<int>& heights, int bricks, int ladders) {
        // Ek min heap banate hain
        priority_queue<int> heap_hai;

        // Har building ke liye check karte hain
        for (int i = 0; i < heights.size() - 1; ++i) {
            // Agar next building current building se unchi hai toh difference calculate karte hain
            int diff = heights[i + 1] - heights[i];

            if (diff > 0) {
                // Agar ladders available hain toh use kar lete hain
                if (ladders > 0) {
                    heap_hai.push(-diff);
                    ladders--;
                } else if (!heap_hai.empty() && -heap_hai.top() < diff) {
                    // Agar ladder nahi hai aur bricks ki zarurat hai toh minimum bricks wali building ka ladder use karte hain
                    bricks += heap_hai.top();
                    heap_hai.pop();
                    heap_hai.push(-diff);
                } else {
                    // Agar ladder nahi hai toh bricks use karte hain
                    bricks -= diff;
                }

                // Agar bricks khatam ho gayi hain toh current building tak hi ja sakte hain
                if (bricks < 0) {
                    return i;
                }
            }
        }

        // Agar saari buildings cross kar li hain toh last building return karte hain
        return heights.size() - 1;
    }
};
