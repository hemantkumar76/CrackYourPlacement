#include <bits/stdc++.h>
using namespace std;

// Input matrix mein rows aur columns
#define R 4
#define C 4

// Histogram ke neeche maximum area ko dhundta hai
// histogram ke details ke liye niche diye gaye article dekhe.


int maxHist(int row[])
{
    // Ek khali stack banaye. 
    // Stack mein hist[] array ke indexes hote hain
    // Stack mein stored bars hamesha
    // unke heights ke increasing order mein hote hain.
    stack<int> result;

    int top_val; // Stack ka top

    int max_area = 0; // Current row (ya histogram) mein max area ko initialize kare

    int area = 0; // Current top ke saath area ko initialize kare

    // Given histogram (ya row) ke sabhi bars ke through run kare
    int i = 0;
    while (i < C) {
        // Agar ye bar stack ke top bar se badi hai,
        // toh ise stack mein push kare
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);

        else {
            // Agar ye bar stack ke top se choti hai, toh
            // rectangle ka area calculate kare jisme stack ke top
            // sabse choti (ya minimum height) bar ho. 'i' hai
            // top ke liye 'right index' aur stack mein top se pehle
            // wala element 'left index' hai
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }

    // Ab stack se remaining bars ko pop kare aur calculate kare
    // area with every popped bar as the smallest bar
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}

// Returns area of the largest rectangle with all 1s in
// A[][]
int maxRectangle(int A[][C])
{
    // Pehle row ke liye area calculate kare aur ise
    // result ke roop mein initialize kare
    int result = maxHist(A[0]);

    // Maximum rectangular area find karne ke liye row par iterate kare
    // considering each row as histogram
    for (int i = 1; i < R; i++) {

        for (int j = 0; j < C; j++)

            // agar A[i][j] 1 hai toh A[i -1][j] ko add kare
            if (A[i][j])
                A[i][j] += A[i - 1][j];

        // Agar current row ke saath rectangle ka area zyada hai
        // toh result update kare
        result = max(result, maxHist(A[i]));
    }

    return result;
}

// Driver code
int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };

    cout << "Maximum rectangle ka area hai "
         << maxRectangle(A);

    return 0;
}
