class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int index = 2;
        int res = 0;
        vector<int> area(n * n);
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Calculate area of each island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int cur = dfs(grid, i, j, index, directions, area);
                    res = max(res, cur);
                    index++;
                }
            }
        }
        
        // Try to change each 0 to 1 and calculate the largest island
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    set<int> neighbor;
                    for (auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0) {
                            neighbor.insert(grid[x][y]);
                        }
                    }
                    int cur = 1;
                    for (int a : neighbor) {
                        cur += area[a - 2];
                    }
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& grid, int i, int j, int index, vector<vector<int>>& directions, vector<int>& area) {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = index;
        int res = 1;
        for (auto& dir : directions) {
            res += dfs(grid, i + dir[0], j + dir[1], index, directions, area);
        }
        area[index - 2] = res;
        return res;
    }
};
