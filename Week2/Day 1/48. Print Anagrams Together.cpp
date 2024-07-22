class Solution{
   public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        
        vector<vector<string>> result; // final result store karne ke liye
        
        unordered_map<string, vector<string>> mp; // har unique sorted string ke anagrams store karne ke liye
        
        for(auto x : string_list){ // har string ke liye
            
            string temp = x; // original string ko save karte hain
            sort(x.begin(), x.end()); // string ko sort karte hain
            mp[x].push_back(temp);  // sorted string ke corresponding anagrams mein original string ko add karte hain
        }

        for(auto temp : mp){ // har unique sorted string ke liye
            vector<string> ans = temp.second; // uske corresponding anagrams ko lete hain
            result.push_back(ans); // aur result mein add karte hain
        }
        return result; // final result return karte hain
    }
};

