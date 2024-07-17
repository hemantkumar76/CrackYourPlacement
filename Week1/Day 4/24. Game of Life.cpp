class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n = board.size();
        int m = board[0].size();

        // Har cell ke liye check karna hai
        for(int a = 0; a < n; a++) {
            for(int b = 0; b < m; b++) {
                int count = 0;
                // Surrounding cells ko check karte hain
                for(int c = a - 1; c <= a + 1; ++c) {
                    for(int d = b - 1; d <= b + 1; ++d) {
                        // Current cell ko skip karte hain
                        if(c == a && d == b) continue;
                        // Agar cell valid range mein hai aur live cell hai, toh count badhao
                        if(c >= 0 && c < n && d >= 0 && d < m && (board[c][d] == 1 || board[c][d] == 3)) {
                            count++;
                        }
                    }
                }

                // Live cell kam ya zyada neighbours hone par die karega
                if(board[a][b] == 1 && (count < 2 || count > 3)) {
                    board[a][b] = 3;  // Mark as to die
                }
                // Dead cell ke exactly 3 live neighbours hone par live ho jayega
                if(board[a][b] == 0 && count == 3) {
                    board[a][b] = 2;  // Mark as to live
                }
            }
        }

        // Final state update karte hain
        for(int a = 0; a < n; ++a) {
            for(int b = 0; b < m; ++b) {
                if(board[a][b] == 3) {
                    board[a][b] = 0;  // Dead
                }
                if(board[a][b] == 2) {
                    board[a][b] = 1;  // Alive
                }
            }
        }
    }
};
