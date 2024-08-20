#include <vector>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<vector<double>> workers(n, vector<double>(2));

        for (int i = 0; i < n; i++) {
            workers[i][0] = static_cast<double>(wage[i]) / quality[i]; 
            workers[i][1] = quality[i];
        }
        sort(workers.begin(), workers.end(), [](const vector<double>& a, const vector<double>& b) {
            return a[0] < b[0];
        });

        priority_queue<int> maxHeap;
        int qualitySum = 0;
        double result = numeric_limits<double>::max();


        for (const auto& worker : workers) {
            double ratio = worker[0];
            int q = static_cast<int>(worker[1]);

            qualitySum += q;
            maxHeap.push(q);

            if (maxHeap.size() > k) {
                qualitySum -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k) {
                result = min(result, ratio * qualitySum);
            }
        }

        return result;
    }
};
