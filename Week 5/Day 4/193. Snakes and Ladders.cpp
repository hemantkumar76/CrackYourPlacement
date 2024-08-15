class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flatten(n * n + 1, -1);  // Flattened board banayenge to easily access squares.
        
        bool leftToRight = true;
        int idx = 1;

        // Board ko flatten karenge.
        for (int i = n - 1; i >= 0; --i) {  // Bottom se start karenge.
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    flatten[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    flatten[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;  // Direction flip karenge har row ke baad.
        }
        
        // BFS use karenge minimum moves find karne ke liye.
        queue<int> q;
        q.push(1);  // Start square 1 se karenge.
        vector<int> visited(n * n + 1, 0);
        visited[1] = 1;
        
        int moves = 0;
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();
                
                if (curr == n * n) return moves;  // Agar last square pe pohoch gaye, return moves.
                
                // Dice ke 6 possible outcomes ke liye loop karenge.
                for (int i = 1; i <= 6; ++i) {
                    int next = curr + i;
                    if (next > n * n) break;  // Agar board ke bahar ja raha hai, break karenge.
                    
                    if (flatten[next] != -1) {
                        next = flatten[next];  // Agar snake ya ladder hai, destination pe move karenge.
                    }
                    
                    if (!visited[next]) {  // Agar next square visited nahi hai to queue mein daalenge.
                        visited[next] = 1;
                        q.push(next);
                    }
                }
            }
            moves++;  // Ek level khatam hone ke baad moves increment karenge.
        }
        
        return -1;  // Agar end tak nahi pohoch paaye, return -1.
    }
};
