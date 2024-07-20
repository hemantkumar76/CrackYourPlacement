class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string res;
        
        // Path ke har character pe loop chalao
        for(int i = 0;  i<path.size(); ++i)
        {
            // Agar character / hai toh skip karo
            if(path[i] == /)    
                continue;
            string temp;
            // Jab tak pura string traverse nahi ho jata aur / nahi milta, tab tak loop chalao
            while(i < path.size() && path[i] != /)
            {
                // Path ko temp string me add karo
                temp += path[i];
                ++i;
            }
            // Agar temp "." hai toh skip karo
            if(temp == ".")
                continue;
            // Agar temp ".." hai toh stack se top element pop karo agar koi element hai toh
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
                // Directory ya file name ko stack me push karo
                st.push(temp);
        }
        
        // Sabhi stack elements ko res me add karo
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
        // Agar koi directory ya file present nahi hai
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};
