#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

// Ek function jo check karta hai ki kya diya gaya
// cell (row, col) DFS mein shamil kiya ja sakta hai
int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
    // row number range mein hai, column
    // number range mein hai aur value 1 hai
    // aur abhi tak visit nahi kiya gaya
    return (row >= 0) && (row < ROW) && (col >= 0)
           && (col < COL)
           && (M[row][col] && !visited[row][col]);
}

// Ek utility function jo DFS karta hai ek
// 2D boolean matrix ke liye. Yeh sirf
// 8 neighbours ko adjacent vertices maanta hai
void DFS(int M[][COL], int row, int col,
         bool visited[][COL])
{
    // Ye arrays use hoti hain
    // ek diye gaye cell ke 8
    // neighbours ke row aur column numbers paane ke liye
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Is cell ko visited mark kare
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k],
                   visited))
            DFS(M, row + rowNbr[k], col + colNbr[k],
                visited);
}

// Main function jo return karta hai
// islands ki count ek diye gaye boolean
// 2D matrix mein
int countIslands(int M[][COL])
{
    // Ek bool array banaye visited cells ko mark karne ke liye.
    // Initially sabhi cells unvisited hote hain
    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Count ko 0 ke roop mein initialize kare aur
    // diye gaye matrix ke sabhi cells ke through traverse kare
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // Agar ek cell ki value 1 hai aur woh
            if (M[i][j] && !visited[i][j]) {
                // abhi tak visit nahi kiya gaya, toh naya island mila
                // Is island ke sabhi cells ko visit kare.
                DFS(M, i, j, visited);

                // aur island count increment kare
                ++count;
            }

    return count;
}

// Driver code
int main()
{
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };

    cout << "Islands ki sankhya hai: " << countIslands(M);

    return 0;
}

// Ye code rathbhupendra ne contribute kiya hai
