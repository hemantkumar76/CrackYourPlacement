class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs_hai(grid, i, j);
                }
            }
        }
        return count;
    }
    void dfs_hai(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return;
        if (grid[i][j] != '1')
            return;
        else
            grid[i][j] = '2';
        dfs_hai(grid, i - 1, j);
        dfs_hai(grid, i + 1, j);
        dfs_hai(grid, i, j + 1);
        dfs_hai(grid, i, j - 1);
    }
};
