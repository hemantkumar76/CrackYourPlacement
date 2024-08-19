class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // Ek priority queue banate hain 
        priority_queue<int> pq;

        // Sabhi elements ko queue me daalte hain
        for (int num : nums) {
            pq.push(num);
        }

        // K-1 largest elements ko queue se hataate hain
        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }

        // Ab jo element queue ke top pe hoga, woh hamara answer hoga
        return pq.top();
    }
};
