class Solution {
public:
    string removeDuplicates(string s, int k) {
        // stack banate hain jismein pair of character aur uska count store hoga
        stack<pair<char, int>> st;
        
        for(char c : s) {
            // agar stack khali hai toh directly push karo
            if(st.empty()) {
                st.push({c, 1});
            } else {
                // agar stack mein top element current character ke equal hai
                // toh uska count badhao
                if(st.top().first == c) {
                    st.top().second++;
                    // agar count k ke equal ho gaya toh usko pop kar do
                    if(st.top().second == k) {
                        st.pop();
                    }
                } else {
                    st.push({c, 1});
                }
            }
        }
        
        // ab stack mein jo elements bach gaye hain unko string mein daalo
        string result = "";
        while(!st.empty()) {
            result = string(st.top().second, st.top().first) + result;
            st.pop();
        }
        
        return result;
    }
};
