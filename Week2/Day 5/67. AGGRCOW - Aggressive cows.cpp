#include<bits/stdc++.h>
using namespace std;

// Ye function check karta hai ki kya hum C cows ko minimum distance maintain karte hue place kar sakte hain
bool place_cow(int stalls[], int n, int c, int min_dist) {
    int last_cow = stalls[0]; // Pehle cow ko pehle stall me place karte hain
    int count = 1; // Ek cow place ho chuki hai
    for (int i = 1; i < n; i++) {
        // Agar current stall aur last cow ke beech ka distance minimum distance se zyada ya barabar hai
        // toh hum yaha ek aur cow place kar sakte hain
        if (stalls[i] - last_cow >= min_dist) {
            last_cow = stalls[i];
            count++;
            // Agar saare cows place ho chuke hain toh hum true return kar sakte hain
            if (count == c)
                return true;
        }
    }
    // Agar saare cows place nahi ho paaye toh hum false return karte hain
    return false;
}

// Ye function largest minimum distance find karta hai
int largest(int stalls[], int n, int c) {
    sort(stalls, stalls+n); // Sabse pehle stalls ki positions ko sort karte hain
    int start = 0; // Start point 0 hota hai
    int end = stalls[n-1] - stalls[0]; // End point last stall tak ka distance hota hai
    while (start < end) {
        int mid = start + (end - start + 1) / 2; // Mid point find karte hain
        // Agar hum C cows ko mid distance maintain karte hue place kar sakte hain
        // toh hum start point ko mid se aage move karte hain
        if (place_cow(stalls, n, c, mid))
            start = mid;
        else
            end = mid - 1; // Nahi toh end point ko mid se peechhe move karte hain
    }
    // Last me, end point return karte hain jo largest minimum distance hota hai
    return end;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        int stalls[n];
        for (int i = 0; i < n; i++)
            cin >> stalls[i];
        cout << largest(stalls, n, c) << endl;
    }
    return 0;
}
