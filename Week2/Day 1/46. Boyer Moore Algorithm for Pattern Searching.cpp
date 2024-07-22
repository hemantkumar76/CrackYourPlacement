#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

// Boyer Moore's bad character heuristic ke liye preprocessing function
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS])
{
    int i;

    // Sabhi occurrences ko -1 se initialize karte hain
    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    // Character ke last occurrence ka actual value fill karte hain
    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

// Boyer Moore Algorithm ke Bad Character Heuristic ka use karke pattern searching function
void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    // bad character array ko fill karte hain badCharHeuristic() function call karke
    badCharHeuristic(pat, m, badchar);

    int s = 0; // s is pattern ka shift hai text ke respect mein
    while (s <= (n - m)) {
        int j = m - 1;

        // Jab tak pattern aur text ke characters match hote hain, tab tak index j ko reduce karte hain
        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        // Agar pattern current shift pe present hai, toh index j -1 ho jayega
        if (j < 0) {
            cout << "pattern occurs at shift = " << s << endl;

            // Pattern ko shift karte hain taki text ka next character pattern ke last occurrence se align ho
            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else
            // Pattern ko shift karte hain taki text ka bad character pattern ke last occurrence se align ho
            s += max(1, j - badchar[txt[s + j]]);
    }
}

// Driver code
int main()
{
    string txt = "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}
