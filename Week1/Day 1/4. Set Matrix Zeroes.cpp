class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(); // Matrix ki rows ki count
        int cols = matrix[0].size(); // Matrix ki columns ki count
        vector<int> row(rows, 0); // Ek row vector banate hain
        vector<int> col(cols, 0); // Ek column vector banate hain

        // Pehle loop mein, hum matrix ke har cell pe jaate hain
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Agar cell ka value 0 hai, toh uske corresponding row aur column ko mark kar dete hain
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Dusre loop mein, hum phir se matrix ke har cell pe jaate hain
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Agar cell ka corresponding row ya column pehle loop mein mark kiya gaya tha, toh cell ko 0 kar dete hain
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
