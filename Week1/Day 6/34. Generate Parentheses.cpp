class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        // Ek khali string se shuru karte hain aur generate function ko call
        // karte hain
        generate(n, n, "", result);
        // Result return karte hain
        return result;
    }
…        // parenthesis add karte hain
        if (open > 0)
            generate(open - 1, close, s + "(", result);
        // Agar humare paas closing parentheses opening se jyada hain, toh hum
        // ek closing parenthesis add karte hain
        if (close > open)
            generate(open, close - 1, s + ")", result);
    }
};
