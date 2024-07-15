class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns
        int row_s = 0, row_e = m - 1;
        int col_s = 0, col_e = n - 1;
        
        // Jab tak koi row ya column bacha hua hai
        while (row_s <= row_e && col_s <= col_e) {
            // Pehle row ke elements add karte hain
            for (int i = col_s; i <= col_e; i++) {
                result.push_back(matrix[row_s][i]);
            }
            row_s++; // Pehle row ko process kar chuke hain
            
            // Last column ke elements add karte hain
            for (int i = row_s; i <= row_e; i++) {
                result.push_back(matrix[i][col_e]);
            }
            col_e--; // Last column ko process kar chuke hain
            
            // Agar koi row bacha hua hai, toh last row ke elements add karte hain
            if (row_s <= row_e) {
                for (int i = col_e; i >= col_s; i--) {
                    result.push_back(matrix[row_e][i]);
                }
            }
            row_e--; // Last row ko process kar chuke hain
            
            // Agar koi column bacha hua hai, toh pehle column ke elements add karte hain
            if (col_s <= col_e) {
                for (int i = row_e; i >= row_s; i--) {
                    result.push_back(matrix[i][col_s]);
                }
            }
            col_s++; // Pehle column ko process kar chuke hain
        }
        
        return result;
    }
};
