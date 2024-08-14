class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // Queue initialize karte hain aur saare land cells ko queue mein daalte hain
        queue<pair<int, int>> q;
        int n = grid.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // max Distance initialize karte hain -1 se
        int distance_hoga = -1;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(auto& dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                // Agar neighboring cell water hai aur visit nahi kiya gaya, toh uska distance update karte hain aur queue mein daalte hain
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                    distance_hoga = max(distance_hoga, grid[nx][ny] - 1);
                }
            }
        }

        // Agar max Distance abhi bhi -1 hai, toh -1 return karte hain. Otherwise, max Distance return karte hain
        return distance_hoga;
    }
};
