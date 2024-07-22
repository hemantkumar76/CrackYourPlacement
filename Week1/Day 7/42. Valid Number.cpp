class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size(); // i: current index, n: size of string
        bool isNumeric = false; // kya number hai?

        // agar space hai toh skip karo
        while (i < n && s[i] == ' ' ) i++;

        // agar + ya - hai toh skip karte hai 
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;

        // digits check karo
        while (i < n && isdigit(s[i])) {
            i++;
            isNumeric = true;
        }

        // agar . hai toh skip karo aur digits check karo
        if (i < n && s[i] == '.') {
            i++;
            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }

        // agar e ya E hai toh skip karo aur digits check karo
        if (isNumeric && i < n && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            isNumeric = false;
            if (i < n && (s[i] == '+' || s[i] == '-')) i++;
            while (i < n && isdigit(s[i])) {
                i++;
                isNumeric = true;
            }
        }

        // agar end tak space hai toh skip karo
        while (i < n && s[i] == ' ' ) i++;

        // agar end tak pahunch gaye hai aur number hai toh true return karo
        return isNumeric && i == n;
    }
};
