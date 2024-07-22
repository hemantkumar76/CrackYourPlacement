class Solution {
public:
    // lol_yar mein sab possible words aur unke corresponding numbers store kar rahe hain
    vector<pair<int, string>> lol_yar ={{1000000000, "Billion"}, {1000000, "Million"}, 
    {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
    {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, 
    {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, 
    {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, 
    {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};
    
    string numberToWords(int num) {
        // agar number 0 hai toh Zero return karte hai 
        if(num == 0)   return "Zero";
        
        // lol_yar ke har element ke liye check karte hai 
        for(auto it: lol_yar)
            // agar number current element ke number se bada ya barabar hai
            if(num >= it.first)
                // toh current element ke number se divide karte hai  aur corresponding word add karte hai 
                // agar number 100 se bada hai toh space add karte hai 
                // agar number current element ke number se divide karne ke baad 0 hai toh kuch add nahi karte hai 
                // nahi toh remaining number ke liye recursively function call karte hai 
                return (num >= 100 ? numberToWords(num/it.first)+" " : "") + it.second + (num%it.first == 0 ? "" : " "+numberToWords(num%it.first));
    
        return "";
    }
};
