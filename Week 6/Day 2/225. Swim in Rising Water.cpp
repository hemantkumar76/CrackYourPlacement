class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(); // Grid ka size lete hain
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 4 directions define karte hain
        vector<vector<bool>> visited(n, vector<bool>(n, false)); // Visited array banate hain
        
        // DFS function define karte hain
        function<bool(int, int, int)> dfs = [&](int x, int y, int t) {
            // Agar hum grid ke boundaries ke bahar hain, ya phir hum already yaha visit kar chuke hain, ya phir grid[x][y] > t hai, to hum false return karte hain
            if(x < 0 || y < 0 || x >= n || y >= n || visited[x][y] || grid[x][y] > t) return false;
            visited[x][y] = true; // Current cell ko visited mark karte hain
            // Agar hum grid ke end tak pahunch gaye hain, to hum true return karte hain
            if(x == n - 1 && y == n - 1) return true;
            // Har direction me move karke dekhte hain
            for(auto &d : dir) if(dfs(x + d[0], y + d[1], t)) return true;
            return false;
        };
        
        // Binary search ka range set karte hain
        int lo = grid[0][0], hi = n * n;
        // Binary search start karte hain
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2; // Mid element calculate karte hain
            // Visited array ko reset karte hain
            for(int i = 0; i < n; i++) fill(visited[i].begin(), visited[i].end(), false);
            // DFS se check karte hain ki kya hum grid ke end tak pahunch sakte hain ya nahi
            if(dfs(0, 0, mid)) hi = mid; // Agar pahunch sakte hain, to 'hi' ko 'mid' se replace karte hain
            else lo = mid + 1; // Agar nahi pahunch sakte, to 'lo' ko 'mid + 1' se replace karte hain
        }
        return lo;
    }
};
