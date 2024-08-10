class Solution {
public:
    vector<vector<int>> lol;
    vector<int> counter, result;
        
    void dfs_hai(int i, int p = -1) {
        for(auto u : lol[i]) {
            if(u == p) continue;
            dfs_hai(u, i);
            counter[i] += counter[u];
            result[i] += result[u] + counter[u];
        }
        counter[i] += 1;
    }

    void dfs_hai2(int i, int n, int p = -1) {
        for(auto u : lol[i]) {
            if(u == p) continue;
            result[u] = result[i] - counter[u] + n - counter[u];
            dfs_hai2(u, n, i);
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        lol.resize(n);
        for(int i = 0; i < n - 1; i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            lol[a].push_back(b);
            lol[b].push_back(a);
        }
        result.resize(n);
        counter.resize(n);
        dfs_hai(0);
        dfs_hai2(0, n);
        return result;
    }
};
