#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // DFS function jo ek node se start karke uske adjacent nodes ko recursively visit karta hai
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
        // Current node ko DFS list mein add karte hain
        storeDfs.push_back(node); 
        // Current node ko visited mark karte hain
        vis[node] = 1; 
        // Current node ke saare adjacent nodes ke liye loop chalate hain
        for(auto it : adj[node]) {
            // Agar koi adjacent node visit nahi hui hai to usko visit karte hain
            if(!vis[it]) {
                dfs(it, vis, adj, storeDfs); 
            }
        }
    }
    
    // Function jo DFS traversal return karta hai
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Vector banate hain jisme hum DFS traversal store karenge
        vector<int> storeDfs; 
        // Visited array banate hain jisme hum track karenge ki kaun se nodes visit hui hain
        vector<int> vis(V+1, 0); 
        // DFS function call karte hain starting node 0 se
        dfs(0, vis, adj, storeDfs); 
        // DFS traversal return karte hain
        return storeDfs; 
    }
};
