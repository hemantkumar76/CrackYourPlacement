class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int orange_fresh = 0;

        // Put the position of all rotten oranges in queue and count the number of fresh oranges
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) {
                    ++orange_fresh;
                }
            }
        }

        // If there are no fresh oranges, return 0
        if(orange_fresh == 0) {
            return 0;
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int minutes = 0;

        // bfs hai 
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                pair<int, int> p = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i) {
                    int nx = p.first + dx[i];
                    int ny = p.second + dy[i];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        --orange_fresh;
                    }
                }
            }
            if(!q.empty()) {
                ++minutes;
            }
        }

        if(orange_fresh > 0) {
            return -1;
        }

        return minutes;
    }
};
