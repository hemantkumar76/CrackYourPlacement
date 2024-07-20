class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Agar array khali hai toh khali string return kar do
        if (strs.empty()) return "";

        // Pehle string ke har character pe loop chalao
        for (int i = 0; i < strs[0].size(); i++) {
            // Baaki sab strings pe loop chalao
            for (int j = 1; j < strs.size(); j++) {
                // Agar character match nahi hota ya string khatam ho jati hai toh ab tak ka common prefix return kar do
                if (i == strs[j].size() || strs[j][i] != strs[0][i])
                    return strs[0].substr(0, i);
            }
        }
        // Agar saare characters match ho gaye toh pehli string hi longest common prefix hai
        return strs[0];
    }
};
