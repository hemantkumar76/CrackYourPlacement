#include <bits/stdc++.h>
using namespace std;

// Check karte hain ki kya koi permutation exist karti hai jo condition satisfy karti hai
bool isPossible(int a[], int b[], int n, int k)
{
    // Array a[] ko decreasing order mein sort karte hain.
    sort(a, a + n);

    // Array b[] ko increasing order mein sort karte hain.
    sort(b, b + n, greater<int>());

    // Har index par condition check karte hain.
    for (int i = 0; i < n; i++)
        if (a[i] + b[i] < k)
            return false; // Agar condition satisfy nahi hoti toh false return karte hain

    return true; // Agar sabhi index par condition satisfy hoti hai toh true return karte hain
}

// Driver Program
int main()
{
    int a[] = { 2, 1, 3 };
    int b[] = { 7, 8, 9 };
    int k = 10;
    int n = sizeof(a) / sizeof(a[0]);

    // Agar permutation possible hai toh "Yes" print karte hain, nahi toh "No"
    isPossible(a, b, n, k) ? cout << "Yes" : cout << "No";
    return 0;
}

// This code is contributed by Aditya Kumar (adityakumar129)
