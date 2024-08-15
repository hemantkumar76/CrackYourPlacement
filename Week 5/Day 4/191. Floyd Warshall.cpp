class Solution {
  public:
	void shortest_distance(vector<vector<int>>& matrix) {
	    int n = matrix.size();
	    
	    // Har node ko ek intermediate node karke check karenge.
	    for(int k = 0; k < n; ++k) {
	        // Har source node ke liye loop.
	        for(int i = 0; i < n; ++i) {
	            // Har destination node ke liye loop.
	            for(int j = 0; j < n; ++j) {
	                
	                // Agar k ke through jaana possible nahi hai, to continue karenge.
	                if(matrix[i][k] == -1 || matrix[k][j] == -1) {
	                    continue;
	                }
	                
	                // Agar direct path nahi hai, to k ke through ka distance assign karenge.
	                if(matrix[i][j] == -1) {
	                    matrix[i][j] = matrix[i][k] + matrix[k][j];
	                }
	                else {
	                    // Warna minimum distance choose karenge.
	                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	                }
	            }
	        }
	    }
	}
};
