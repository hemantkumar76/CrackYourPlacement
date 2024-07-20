class Solution {
public:
    // Ek function banate hain jo check karta hai ki kya ek string palindrome hai ya nahi.
    bool check(string s,int i,int j){
        // String ke dono ends se shuru karte hain aur center ki taraf move karte hain.
        while(i<=j)
        {
            // Agar characters match nahi karte, toh false return kar do.
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        // Agar saare characters match ho gaye toh true 
        return true;
    }

    bool validPalindrome(string s) {
        // String ke dono ends se shuru karte hain.
        int i=0,j=s.size()-1;
        while(i<=j){
            // Agar characters match nahi karte, toh ek character delete karke dekho ki kya bachi hui string palindrome hai ya nahi.
            if(s[i]!=s[j]){
                return check(s,i+1,j) || check(s,i,j-1);
            }
            else{
                // Agar characters match karte hain, toh dono pointers ko center ki taraf move karo.
                i++;
                j--;
            }
        }
        return true;
    }
};
