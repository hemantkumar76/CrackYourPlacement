class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // 2D array initialize karte hain shortest distances store karne ke liye
        vector<vector<int>> dist(n, vector<int>(n, 1e5));
        for(int i = 0; i < n; ++i) dist[i][i] = 0;
        for(auto& edge : edges) {
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }

        // Floyd-Warshall algorithm perform karte hain shortest distances find karne ke liye
        for(int k = 0; k < n; ++k) {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Har city ke liye, reachable cities ki count karte hain
        vector<int> count(n);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dist[i][j] <= distanceThreshold) ++count[i];
            }
        }

        // City find karte hain jiske sabse kam reachable cities hain
        int minCount = n, city = 0;
        for(int i = 0; i < n; ++i) {
            if(count[i] <= minCount) {
                minCount = count[i];
                city = i;
            }
        }

        return city;
    }
};
