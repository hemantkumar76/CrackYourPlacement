#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool found = false;

        // Pehle island ko dhundho aur usko queue me daalo
        for(int i=0; i<n && !found; i++) {
            for(int j=0; j<n && !found; j++) {
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, q);
                    found = true;
                }
            }
        }

        // Doosre island tak ka shortest distance dhundho
        int level = 0;
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                pair<int, int> cur = q.front();
                q.pop();
                for(auto dir : dirs) {
                    int x = cur.first + dir[0], y = cur.second + dir[1];
                    if(x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == 2) {
                        continue;
                    }
                    if(grid[x][y] == 1) {
                        return level;
                    }
                    q.push({x, y});
                    grid[x][y] = 2;
                }
            }
            level++;
        }
        return 0;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, queue<pair<int, int>>& q) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid.size() || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, i+1, j, q);
        dfs(grid, i-1, j, q);
        dfs(grid, i, j+1, q);
        dfs(grid, i, j-1, q);
    }
};
