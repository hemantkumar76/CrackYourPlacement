//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        // P ke har character ki frequency count karte hain
        vector<int> pat(256, 0);
        for (char c : p) pat[c]++;
        
        int start = 0, start_index = -1, min_len = INT_MAX;
        int count = 0;
        vector<int> str(256, 0);
        
        for (int j = 0; j < s.length(); j++) {
            str[s[j]]++;
            
            // Agar P ke character S me hain, toh count ko increment karte hain
            if (pat[s[j]] != 0 && str[s[j]] <= pat[s[j]]) count++;
            
            // Jab count P ke length ke equal ho jaye, toh hum window ko minimize karte hain
            if (count == p.length()) {
                while (str[s[start]] > pat[s[start]] || pat[s[start]] == 0) {
                    if (str[s[start]] > pat[s[start]]) str[s[start]]--;
                    start++;
                }
                
                // Window ka length update karte hain
                int len_window = j - start + 1;
                if (min_len > len_window) {
                    min_len = len_window;
                    start_index = start;
                }
            }
        }
        
        // Agar koi window exist nahi karti, toh -1 return karte hain
        if (start_index == -1) return "-1";
        
        // Smallest window return karte hain
        return s.substr(start_index, min_len);
    }
};

// } Driver Code Ends
