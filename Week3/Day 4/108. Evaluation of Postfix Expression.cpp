class Solution

{
    public:
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for(int i = 0; i < S.length(); i++) {
            if(isdigit(S[i]))
                st.push(S[i] - '0');
            else {
                int val1 = st.top(); st.pop();
                int val2 = st.top(); st.pop();
                switch(S[i]) {
                    case '+': st.push(val2 + val1); break;
                    case '-': st.push(val2 - val1); break;
                    case '*': st.push(val2 * val1); break;
                    case '/': st.push(val2 / val1); break;
                }
            }
        }
        return st.top();
    }
};
