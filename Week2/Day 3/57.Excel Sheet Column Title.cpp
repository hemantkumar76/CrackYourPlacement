#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        // Ek khali string banate hain
        string result = "";

        // Jab tak columnNumber 0 nahi ho jata, tab tak loop chalate hain
        while(columnNumber) {
            // columnNumber se 1 subtract karte hain kyunki index 0 se start hota hai
            columnNumber--;
            
            // columnNumber ko 26 se divide karke remainder nikalte hain
            // Is remainder ko 'A' se add karke corresponding character milta hai
            // Ye character hum result string ke start mein insert karte hain
            result.insert(result.begin(), 'A' + columnNumber % 26);
            
            // Ab columnNumber ko 26 se divide karte hain
            columnNumber /= 26;
        }

        // Last mein, hum result string return karte hain
        return result;
    }
};
