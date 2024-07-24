#include <bits/stdc++.h>
using namespace std;

/* Function jo x ki ceiling ka index dhoondta hai arr[low..high] mein */
int ceilSearch(int arr[], int low, int high, int x) 
{ 
    int i; 
    
    /* Agar x chota ya barabar hai pehle element se, 
        toh return karo pehla element */
    if(x <= arr[low]) 
        return low; 
    
    /* Varna, linearly search karo ceil value ke liye */
    for(i = low; i < high; i++) 
    { 
        if(arr[i] == x) 
        return i; 
    
        /* agar x arr[i] aur arr[i+1] ke beech mein hai including 
        arr[i+1], toh return karo arr[i+1] */
        if(arr[i] < x && arr[i+1] >= x) 
        return i+1; 
    }	 
    
    /* Agar yahan tak pahunch gaye toh x hai last element 
        se bada array ka, is case mein return karo -1 */
    return -1; 
} 


/* Driver code*/
int main() 
{ 
    int arr[] = {1, 2, 8, 10, 10, 12, 19}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 3; 
    int index = ceilSearch(arr, 0, n-1, x); 
    if(index == -1) 
        cout << "Ceiling of " << x << " doesn't exist in array "; 
    else
        cout << "ceiling of " << x << " is " << arr[index]; 
    
    return 0; 
} 

// This is code is contributed by rathbhupendra
