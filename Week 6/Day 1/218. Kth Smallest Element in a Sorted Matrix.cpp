#include <queue>
#include <vector>

class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        // Ek max heap banate hain
        priority_queue<int> max_heap;

        // Matrix ke har element ke liye
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                // Element ko heap me daalte hain
                max_heap.push(matrix[i][j]);

                // Agar heap ka size k se bada ho gaya hai
                if (max_heap.size() > k) {
                    // Toh heap ke top element ko hata dete hain
                    max_heap.pop();
                }
            }
        }

        // Ab jo element heap ke top pe hoga, woh hamara answer hoga
        return max_heap.top();
    }
};
