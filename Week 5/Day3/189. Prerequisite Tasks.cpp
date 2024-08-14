class Solution {
public:
    bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
        // Adjacency list aur in-degree array initialize karte hain
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);
        for(auto& p : prerequisites) {
            adj[p.second].push_back(p.first);
            ++indegree[p.first];
        }

        // Queue initialize karte hain aur saare vertices jinke in-degree 0 hai queue mein daalte hain
        queue<int> q;
        for(int i = 0; i < N; ++i) {
            if(indegree[i] == 0) q.push(i);
        }

        // BFS perform karte hain
        int count = 0;
        while(!q.empty()) {
            int v = q.front(); q.pop();
            ++count;
            for(int u : adj[v]) {
                if(--indegree[u] == 0) q.push(u);
            }
        }

        // Agar saare vertices visit ho gaye, toh true return karte hain. Otherwise, false return karte hain
        return count == N;
    }
};
