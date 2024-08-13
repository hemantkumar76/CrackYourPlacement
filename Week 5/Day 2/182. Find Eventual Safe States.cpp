#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // Sabhi nodes ko initially unvisited mark karo
        vector<int> res;

        // Har node ke liye check karo ki woh safe hai ya nahi
        for(int i=0; i<n; i++) {
            if(dfs(graph, i, color)) {
                res.push_back(i);
            }
        }
        
        return res; // Safe nodes return karo
    }
    
private:
    bool dfs(vector<vector<int>>& graph, int node, vector<int>& color) {
        if(color[node] > 0) { // Agar node visited hai toh check karo ki woh safe hai ya nahi
            return color[node] == 2;
        }
        
        color[node] = 1; // Node ko visiting mark karo
        for(int nei : graph[node]) { // Har neighbour ke liye check karo ki woh safe hai ya nahi
            if(!dfs(graph, nei, color)) {
                return false;
            }
        }
        
        color[node] = 2; // Node ko visited and safe mark karo
        return true;
    }
};
