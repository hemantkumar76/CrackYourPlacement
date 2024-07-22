class Solution {
public:
    int calculate(string s) {
        int total = 0;        
        int num_curr = 0;   
        int num_last = 0;      
        char operation = '+'; 

        for (int i = 0; i < s.length(); i++) {
            char char_curr = s[i];
            // agar curr char number hai toh use num me add karte hai 
            if (isdigit(char_curr)) {
                num_curr = (num_curr * 10) + (char_curr - '0');
            }
            // agar curr chat operator hai ya last character hai toh operation
            // perform karo
            if (!isdigit(char_curr) && !isspace(char_curr) ||
                i == s.length() - 1) {
                if (operation == '+' || operation == '-') {
                    total += num_last;
                    num_last = (operation == '+') ? num_curr : -num_curr;
                } else if (operation == '*') {
                    num_last = num_last * num_curr;
                } else if (operation == '/') {
                    num_last = num_last / num_curr;
                }
                operation = char_curr;
                num_curr = 0;
            }
        }
        total += num_last;
        return total;
    }
};
