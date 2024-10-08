class Solution {
public:
    int uniquePaths(int m, int n) {
        
        int N = n+m-2;
        
        int r = m-1;
        
        double result = 1;
        
        for(int i = 1; i <= r; i++)
        {
            result = result * (N-r + i)/ i;
        }
        
        return (int)result;
        
    }
};
