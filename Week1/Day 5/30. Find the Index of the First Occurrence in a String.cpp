class Solution {
public:
    int strStr(string haystack, string needle) {
        // pehle check kar lete hai ki agar humara haystack ka length less hai
        // ya nhi agar less hua then immediately false return kar denge.

        if (haystack.size() < needle.size()) {
            return -1;
        }

        // loop lagate hai for traversing the haystack

        for (int i = 0; i <= haystack.size() - needle.size(); i++) 
        {
            if(haystack.substr(i, needle.length()) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};
