class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
    {
        // Knight ke possible moves
        int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
        int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
        
        // Queue for BFS
        queue<pair<pair<int, int>, int>> q;
        
        // Visited array
        vector<vector<bool>> vis(N+1, vector<bool>(N+1, false));
        
        // Knight ki starting position
        q.push({{KnightPos[0], KnightPos[1]}, 0});
        vis[KnightPos[0]][KnightPos[1]] = true;
        
        while(!q.empty()) {
            auto cell = q.front();
            q.pop();
            
            int x = cell.first.first, y = cell.first.second, dis = cell.second;
            
            // Agar target position pe pahunch gaye hain toh distance return karo
            if(x == TargetPos[0] && y == TargetPos[1]) {
                return dis;
            }
            
            // All possible moves try karo
            for(int i=0; i<8; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                
                // Agar move valid hai aur us cell pe pehle se visit nahi kiya hai toh queue me daalo
                if(nx >= 1 && ny >= 1 && nx <= N && ny <= N && !vis[nx][ny]) {
                    q.push({{nx, ny}, dis + 1});
                    vis[nx][ny] = true;
                }
            }
        }
        
        
        return -1;
    }
};
