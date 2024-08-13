#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs1(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true; // Node ko visited mark karo
        for(auto it : adj[node]) { // Har neighbour ke liye dfs call karo
            if(!visited[it]) {
                dfs1(it, adj, visited, st);
            }
        }
        st.push(node); // Node ko stack me daalo
    }
    
    void dfs2(int node, vector<vector<int>>& transpose, vector<bool>& visited) {
        visited[node] = true; // Node ko visited mark karo
        for(auto it : transpose[node]) { // Har neighbour ke liye dfs call karo
            if(!visited[it]) {
                dfs2(it, transpose, visited);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++) { // Pehle dfs call karo
            if(!visited[i]) {
                dfs1(i, adj, visited, st);
            }
        }
        
        vector<vector<int>> transpose(V); // Transpose graph banao
        for(int i=0; i<V; i++) {
            visited[i] = false;
            for(auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }
        
        int count = 0;
        while(!st.empty()) { // Stack se nodes nikalo aur unke liye dfs call karo
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                count++; // Strongly connected components count karo
                dfs2(node, transpose, visited);
            }
        }
        
        return count; // Strongly connected components return karo
    }
};
