// C++ program ki check karne ke liye ki kya subarray ko reverse karne se array sort ho jayega ya nahi
#include<bits/stdc++.h> 
using namespace std; 

// Agar subarray ko reverse karne se array sort ho jata hai toh true return karega, nahi toh false.
bool checkReverse(int arr[], int n) 
{ 
    // Array ko copy karte hain.
    int temp[n]; 
    for (int i = 0; i < n; i++) 
        temp[i] = arr[i]; 

    // Copied array ko sort karte hain.
    sort(temp, temp + n); 

    // Pehla mismatch dhundte hain.
    int front; 
    for (front = 0; front < n; front++) 
        if (temp[front] != arr[front]) 
            break; 

    // Last mismatch dhundte hain.
    int back; 
    for (back = n - 1; back >= 0; back--) 
        if (temp[back] != arr[back]) 
            break; 

    // Agar pura array sorted hai
    if (front >= back) 
        return true; 

    // Check karte hain ki subarray decreasing hai ya nahi.
    do
    { 
        front++; 
        if (arr[front - 1] < arr[front]) 
            return false; 
    } while (front != back); 

    return true; 
} 

// Driver Program 
int main() 
{ 
    int arr[] = { 1, 2, 5, 4, 3 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 

    checkReverse(arr, n)? (cout << "Haan" << endl): 
                        (cout << "Nahi" << endl); 
    return 0; 
} 
