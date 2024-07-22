class Solution {
public:
    string minWindow(string s, string t) {
        // frequency map banate hain t ke characters ka
        unordered_map<char, int> freq;
        for(char c : t) freq[c]++;
        
        // start aur end pointers initialize karte hain
        int start = 0, end = 0, counter = t.size(), minLen = INT_MAX, minStart = 0;
        
        // end pointer ko s ke end tak move karte hain
        while(end < s.size()) {
            // agar current character t mein hai toh counter decrement karte hain
            if(freq[s[end]] > 0) counter--;
            // frequency map mein current character ki frequency decrement karte hain
            freq[s[end]]--;
            end++;
            
            // jab tak counter 0 hai (yaani saare t ke characters window mein hain)
            while(counter == 0) {
                // agar current window choti hai toh minLen update karte hain
                if(end - start < minLen) {
                    minLen = end - start;
                    minStart = start;
                }
                
                // frequency map mein start character ki frequency increment karte hain
                freq[s[start]]++;
                // agar start character t mein hai toh counter increment karte hain
                if(freq[s[start]] > 0) counter++;
                // start pointer ko increment karte hain
                start++;
            }
        }
        
        // agar minLen abhi bhi INT_MAX hai toh empty string return karte hain
        if(minLen == INT_MAX) return "";
        // nahi toh minimum window substring return karte hain
        return s.substr(minStart, minLen);
    }
};
