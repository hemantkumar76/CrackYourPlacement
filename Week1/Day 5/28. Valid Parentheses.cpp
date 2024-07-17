class Solution {
public:
    bool isValid(string s) {
        stack<char> st; // Ek stack banate hain
        for (int i = 0; i < s.length(); i++) { // String ke har character ke liye
            char ch = s[i]; // Current character

            if (ch == '(' || ch == '{' || ch == '[') { // Agar character open bracket hai
                st.push(ch); // Toh use stack me daalte hain
            }

            else { // Agar character close bracket hai

                if (!st.empty()) { // Agar stack khali nahi hai
                    char top = st.top(); // Stack ke top element ko lete hain
                    // Agar top element aur current character ek valid pair banate hain
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {

                        st.pop(); // Toh top element ko stack se hata dete hain
                    } else { // Nahi toh string valid nahi hai
                        return false;
                    }
                } else { // Agar stack khali hai toh string valid nahi hai

                    return false;
                }
            }
        }

        // Agar stack khali hai toh string valid hai, nahi toh valid nahi hai
        if (st.empty()) {
            return true;
        }
        return false;
    }
};
