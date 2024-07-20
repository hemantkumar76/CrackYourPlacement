class Solution {
public:
    string intToRoman(int num) {
        // Roman numerals aur unke values ki list banate hain
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";
        // Greedy approach ka use karte hain
        for (int i = 0; i < values.size() && num > 0; i++) {
            // Current Roman numeral ke value ko number se utni baar subtract karte hain jitni baar ho sake
            while (values[i] <= num) {
                num -= values[i];
                result += symbols[i];
            }
        }
        // Result return karte hain
        return result;
    }
};
