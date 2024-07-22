class Solution {
public:
    string reverseWords(string s) {
        // Ek vector banate hain jisme hum words store karenge
        vector<string> words;

        // String ke har character pe iterate karte hain
        for (int i = 0; i < s.size(); i++) {
            // Agar character space nahi hai toh word start hua
            if (s[i] != ' ') {
                // Word ka end dhundte hain
                int j = i;
                while (j < s.size() && s[j] != ' ') j++;
                // Word ko vector me add karte hain
                words.push_back(s.substr(i, j - i));
                // i ko update karte hain
                i = j;
            }
        }

        // Words ko reverse order me join karte hain
        string result = "";
        for (int i = words.size() - 1; i >= 0; i--) {
            result += words[i];
            // Last word ke baad space nahi chahiye
            if (i > 0) result += " ";
        }

        // Result return karte hain
        return result;
    }
};
