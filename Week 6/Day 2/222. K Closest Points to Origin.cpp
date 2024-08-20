class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap banate hain jisme hum points ko unke distance ke according store karenge
        priority_queue<pair<int, vector<int>>> heap_hai;
        
        // Points array ke har element ke liye
        for (auto& point : points) {
            // Distance calculate karte hain
            int dist = point[0]*point[0] + point[1]*point[1];
            
            // Distance aur point ko heap me daalte hain
            heap_hai.push({dist, point});
            
            // Agar heap ka size k se bada ho jaye
            if (heap_hai.size() > k) {
                // Toh heap ka top element remove kar dete hain
                heap_hai.pop();
            }
        }
        
        // Result array banate hain
        vector<vector<int>> result;
        
        // Heap me jo elements bachenge, wohi humare k closest points honge
        while (!heap_hai.empty()) {
            result.push_back(heap_hai.top().second);
            heap_hai.pop();
        }

        return result;
    }
};
