#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
  // map se karte hai 
    unordered_map<char, int> count;
    for (int i = 0; i < str.length(); i++) {
      // string ki valu eincrease karte hai 
        count[str[i]]++;
    }
    // iterate karte hai 
    for (auto it : count) {
        if (it.second > 1)
            cout << it.first << ", count = " << it.second
    }
}
int main()
{
    string str = "HemantKumar";
    printDups(str);
    return 0;
}
