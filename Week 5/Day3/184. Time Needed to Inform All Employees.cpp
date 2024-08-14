class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Adjacency list banate hain manager-subordinate relationship ke liye
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; ++i) {
            if(manager[i] != -1) {
                graph[manager[i]].push_back(i);
            }
        }

        // DFS shuru karte hain company ke head se
        return dfs(headID, graph, informTime);
    }

private:
    int dfs(int curr, vector<vector<int>>& graph, vector<int>& informTime) {
        // max time initialize karte hain 0 se
        int maxTime = 0;
        for(int i = 0; i < graph[curr].size(); ++i) {
            // Har employee ke liye, unke sabhi subordinates visit karte hain recursively
            // Aur time calculate karte hain inform karne ka
            maxTime = max(maxTime, dfs(graph[curr][i], graph, informTime));
        }
        // max time return karte hain
        return maxTime + informTime[curr];
    }
};
