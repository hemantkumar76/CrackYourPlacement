class DSU {
public:
    vector<int> parent;
    DSU(int N) {
        parent.resize(N);
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // DSU initialize karte hain
        DSU dsu(20000);
        for (auto& stone : stones)
            // Har stone ke liye, uske row aur column ko union karte hain DSU mein
            dsu.Union(stone[0], stone[1] + 10000);
        unordered_map<int, int> parentCount;
        for (auto& stone : stones)
            // Har parent ke liye, uske children ki count karte hain
            parentCount[dsu.find(stone[0])]++;
        int maxStones = 0;
        for (auto& pc : parentCount)
            // Maximum stones jo remove kiye ja sakte hain, total children se 1 subtract karke milenge
            maxStones += pc.second - 1;
        return maxStones;
    }
};
