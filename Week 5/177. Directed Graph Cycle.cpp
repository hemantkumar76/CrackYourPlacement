class Solution {
public:
    // Function jo check karta hai ki kya directed graph mein cycle hai ya nahi
    bool isCyclic(int V, vector<int> adj[]) {
        // Visited array banate hain jisme hum track karenge ki kaun se nodes visit hui hain
        vector<int> vis(V, 0);
        // DFS array banate hain jisme hum track karenge ki kaun se nodes DFS call stack mein hain
        vector<int> dfsVis(V, 0);
        for(int i = 0; i < V; i++) {
            // Agar koi node visit nahi hui hai to usko visit karte hain
            if(!vis[i]) {
                if(lol(i, adj, vis, dfsVis)) return true;
            }
        }
        return false;
    }

    // Function jo DFS use karke check karta hai ki kya cycle hai ya nahi
    bool lol(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsVis) {
        vis[node] = 1; // Current node ko visited mark karte hain
        dfsVis[node] = 1; // Current node ko DFS call stack mein add karte hain
        for(auto it : adj[node]) { // Current node ke saare adjacent nodes ke liye loop chalate hain
            if(!vis[it]) { // Agar koi adjacent node visit nahi hui hai to usko visit karte hain
                if(lol(it, adj, vis, dfsVis)) return true;
            }
            else if(dfsVis[it]) { // Agar koi adjacent node visit hui hui hai aur wo DFS call stack mein hai to cycle hai
                return true;
            }
        }
        dfsVis[node] = 0; // Current node ko DFS call stack se remove karte hain
        return false;
    }
};
