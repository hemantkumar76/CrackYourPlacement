// C++ program jo minimum cost find karta hai
// taki sabhi elements equal ho jaye
#include <bits/stdc++.h>
using namespace std;

// Utility method jo cost compute karta hai, jab
// array ke sabhi values ko X ke barabar banaya jata hai
int computeCost(int arr[], int N, int X)
{
    int cost = 0;
    for (int i = 0; i < N; i++)
        cost += abs(arr[i] - X);
    return cost;
}

// Method jo minimum cost find karta hai taki sabhi
// elements equal ho jaye
int minCostToMakeElementEqual(int arr[], int N)
{
    int low, high;
    low = high = arr[0];

    // ternary search ke liye limits set kar rahe hain
    // smallest aur largest element ke dwara
    for (int i = 0; i < N; i++) {
        if (low > arr[i])
            low = arr[i];
        if (high < arr[i])
            high = arr[i];
    }

    /* loop tab tak chalta hai jab tak low aur high
    ke beech ka difference 3 se kam nahi ho jata,
    kyunki uske baad
    mid1 aur mid2 start ho jayenge repeat
    */
    while ((high - low) > 2) {

        // mid1 aur mid2 search space ke
        // representative array equal values hain
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        int cost1 = computeCost(arr, N, mid1);
        int cost2 = computeCost(arr, N, mid2);

        // agar mid2 point zyada total cost deta hai,
        // toh third part ko skip karo
        if (cost1 < cost2)
            high = mid2;

        // agar mid1 point zyada total cost deta hai,
        // toh first part ko skip karo
        else
            low = mid1;
    }

    // computeCost optimum cost ko prapt karta hai by sending
    // low aur high ka average as X
    return computeCost(arr, N, (low + high) / 2);
}

// Driver code to test above method
int main()
{
    int arr[] = { 1, 100, 101 };
    int N = sizeof(arr) / sizeof(int);
    cout << minCostToMakeElementEqual(arr, N);
    return 0;
}
