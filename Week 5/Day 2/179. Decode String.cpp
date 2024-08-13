#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts; // yeh stack hame repeat karne ke liye counts store karega
        stack<string> result; // yeh stack hame intermediate results store karega
        string res = ""; // yeh final result store karega
        int count = 0; // yeh current count store karega
        
        for(char ch : s) {
            if(isdigit(ch)) { // agar character digit hai toh count update karo
                count = count * 10 + (ch - '0');
            } else if(ch == '[') { // agar character '[' hai toh current result aur count ko stack me daalo
                counts.push(count);
                result.push(res);
                // reset karo count aur res ko
                count = 0;
                res = "";
            } else if(ch == ']') { // agar character ']' hai toh top element ko pop karo aur usko repeat karo
                string temp = result.top();
                result.pop();
                int repeat = counts.top();
                counts.pop();
                for(int i=0; i<repeat; i++) {
                    temp += res;
                }
                res = temp;
            } else { // agar character letter hai toh usko res me add karo
                res += ch;
            }
        }
        
        return res;
    }
};
