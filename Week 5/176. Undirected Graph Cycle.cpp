class Solution {
public:
    // Function jo check karta hai ki kya graph mein cycle hai ya nahi
    bool isCycle(int V, vector<int> adj[]) {
        // Visited array banate hain jisme hum track karenge ki kaun se nodes visit hui hain
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++) {
            // Agar koi node visit nahi hui hai to usko visit karte hain
            if(!vis[i]) {
                if(lol(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }

    // Function jo DFS use karke check karta hai ki kya cycle hai ya nahi
    bool lol(int node, int parent, vector<int> adj[], vector<int> &vis) {
        vis[node] = 1; // Current node ko visited mark karte hain
        for(auto it : adj[node]) { // Current node ke saare adjacent nodes ke liye loop chalate hain
            if(!vis[it]) { // Agar koi adjacent node visit nahi hui hai to usko visit karte hain
                if(lol(it, node, adj, vis)) return true;
            }
            else if(it != parent) { // Agar koi adjacent node visit hui hui hai aur wo parent nahi hai to cycle hai
                return true;
            }
        }
        return false;
    }
};
