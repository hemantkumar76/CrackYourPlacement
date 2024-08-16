class Solution {
public:
    vector<vector<int>> result; // Critical connections store karne ke liye
    vector<int> disc, low; // Discovery time aur Lowest discovery time arrays
    vector<vector<int>> adj; // Adjacency list
    int time = 0; // Global time tracker for DFS

    void dfs(int u, int parent) {
        disc[u] = low[u] = ++time; // Node ki discovery time set karenge
        for (int v : adj[u]) { // Har adjacent node ko traverse karenge
            if (v == parent)
            {
                continue; // Agar parent node hai toh skip karenge
            }

            if (disc[v] == -1) { // Agar adjacent node pehle discover nahi hui
                dfs(v, u); // DFS call karenge us node ke liye
                low[u] = min(low[u], low[v]); // Low time update karenge

                if (low[v] > disc[u]) { // Agar low time zyada hai, toh ye connection critical hai
                    result.push_back({u, v});
                }
            } else { // Agar already visited hai
                low[u] = min(low[u], disc[v]); // Low time update karenge
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n); // Adjacency list ka size n set karenge
        disc.resize(n, -1); // Discovery time array initialize karenge
        low.resize(n, -1); // Low time array initialize karenge

        // Graph banane ke liye connections ko adjacency list mein daalenge
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        // DFS call karenge har node ke liye, agar wo discover nahi hui toh
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i, -1); // Root node ke parent ko -1 set karenge
            }
        }

        return result; // Critical connections return karenge
    }
};
