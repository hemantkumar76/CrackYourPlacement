class Solution
{
	public:
	// Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // Priority queue use karenge taaki sabse chhoti edge pehle mile (min-heap).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Visited array banayenge taaki pata chale kaunse nodes visit ho chuke hain.
        vector<bool> visited(V, false);
        
        // Minimum spanning tree ka total weight store karne ke liye variable.
        int mst_weight = 0;
        
        // Shuruaat karenge vertex 0 se. (weight, node) format mein push karenge.
        pq.push({0, 0});
        
        // Jab tak priority queue khali nahi ho jaati, loop chalayenge.
        while(!pq.empty()) {
            // Sabse chhoti weight wali edge nikaalenge.
            pair<int, int> p = pq.top();
            pq.pop();
            int weight = p.first;
            int node = p.second;
            
            // Agar node already visited hai, to usko skip karenge.
            if (visited[node]) continue;
            
            // Node ko visit mark karenge aur uska weight MST mein add karenge.
            visited[node] = true;
            mst_weight += weight;
            
            // Sab connected nodes ko priority queue mein daalenge agar unko visit nahi kiya hai.
            for (auto &edge : adj[node]) {
                int adjNode = edge[0];
                int edgeWeight = edge[1];
                if (!visited[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        
        // MST ka total weight return karenge.
        return mst_weight;
    }
};
