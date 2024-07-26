class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        bool exists[n + 1];
        memset(exists, false, sizeof(exists));
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0 && arr[i] <= n) {
                exists[arr[i]] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!exists[i]) {
                return i;
            }
        }

        return n + 1;
    } 
};

