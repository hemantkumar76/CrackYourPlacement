class Solution {
public:
    bool canAllocate(int arr[], int n, int m, long long maxPages) {
        int students = 1;
        long long currentPages = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > maxPages) {
                return false; // If any book has pages more than maxPages, allocation is not possible
            }
            
            if (currentPages + arr[i] > maxPages) {
                students++;
                currentPages = arr[i];
                if (students > m) {
                    return false;
                }
            } else {
                currentPages += arr[i];
            }
        }
        
        return true;
    }
    
    long long findPages(int n, int arr[], int m) {
        if (m > n) {
            return -1;
        }
        
        long long low = *max_element(arr, arr + n);
        long long high = accumulate(arr, arr + n, 0LL);
        long long result = high;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (canAllocate(arr, n, m, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};
