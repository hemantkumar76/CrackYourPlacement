class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Do pointers banayenge jo strings ke end se start karenge
        int i = s.length() - 1, j = t.length() - 1;

        // Jab tak dono pointers 0 se bade hain, tab tak loop chalayenge
        while (i >= 0 || j >= 0) {
            // Dono strings ke liye backspace count karenge
            int s_backspace = 0;
            int t_backspace = 0;

            // Jab tak s ki current character '#' hai ya backspace count positive hai, tab tak loop chalayenge
            while (i >= 0 && (s_backspace > 0 || s[i] == '#')) {
                // Agar current character '#' hai to backspace count badhayenge
                // Nahi to backspace count ghatayenge
                s_backspace += (s[i] == '#') ? 1 : -1;
                i--;
            }

            // Same process t ke liye repeat karenge
            while (j >= 0 && (t_backspace > 0 || t[j] == '#')) {
                t_backspace += (t[j] == '#') ? 1 : -1;
                j--;
            }

            // Agar dono strings ke current characters match nahi karte, to false return karenge
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }

            // Agar ek string khatam ho gayi hai aur dusri nahi, to false return karenge
            if ((i >= 0) != (j >= 0)) {
                return false;
            }

            // Dono pointers ko ek step peeche le jayenge
            i--;
            j--;
        }
        return true;
    }
};
