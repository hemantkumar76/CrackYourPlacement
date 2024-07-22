#include <bits/stdc++.h>
using namespace std;

#define d 256  // d yani number of characters in the input alphabet

void khojo(char pattern[], char text[], int primeNumber)
{
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int i, j;
    int patternHash = 0; // hash value for pattern
    int textHash = 0; // hash value for text
    int h = 1;

    // h ki value hogi "pow(d, patternLength-1)%primeNumber"
    for (i = 0; i < patternLength - 1; i++)
        h = (h * d) % primeNumber;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < patternLength; i++) {
        patternHash = (d * patternHash + pattern[i]) % primeNumber;
        textHash = (d * textHash + text[i]) % primeNumber;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= textLength - patternLength; i++) {

        // Check the hash values of current window of text and pattern.
        // Agar hash values match hoti hai toh check karo characters one by one
        if (patternHash == textHash) {
            /* Check for characters one by one */
            for (j = 0; j < patternLength; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }

            // agar patternHash == textHash and pattern[0...patternLength-1] = text[i, i+1, ...i+patternLength-1]
            if (j == patternLength)
                cout << "Pattern mil gaya index " << i << " pe" << endl;
        }

        // Calculate hash value for next window of text:
        // Remove leading digit, add trailing digit
        if (i < textLength - patternLength) {
            textHash = (d * (textHash - text[i] * h) + text[i + patternLength]) % primeNumber;

            // Ho sakta hai ki textHash ki value negative aaye, usko positive kar do
            if (textHash < 0)
                textHash = (textHash + primeNumber);
        }
    }
}

/* Driver code */
int main()
{
    char text[] = "GEEKS FOR GEEKS";
    char pattern[] = "GEEK";

    // hum mod lete hai overflow hone se bachne ke liye lekin hume chahiye bada q tak ki collision na ho
    int primeNumber = INT_MAX;

    // Function Call
    khojo(pattern, text, primeNumber);
    return 0;
}
