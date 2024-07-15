class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Board ke har cell ke liye check karte hain
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // Agar word exist karta hai, toh true return karte hain
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        // Agar koi word nahi mila, toh false return karte hain
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index) {
        // Agar index word ke length se equal hai, toh true return karte hain
        if (index == word.size()) {
            return true;
        }
        // Agar i ya j board ke boundaries ke bahar hai, ya current cell word ke current character se match nahi karta, toh false return karte hain
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index]) {
            return false;
        }
        // Current cell ko temporarily '*' se mark karte hain, taki hum ise dubara use na kare
        char temp = board[i][j];
        board[i][j] = '*';
        // 4 directions mein DFS karte hain
        bool found = dfs(board, word, i + 1, j, index + 1) || dfs(board, word, i - 1, j, index + 1) || dfs(board, word, i, j + 1, index + 1) || dfs(board, word, i, j - 1, index + 1);
        // Current cell ko unmark karte hain
        board[i][j] = temp;
        // Found ki value return karte hain
        return found;
    }
};
