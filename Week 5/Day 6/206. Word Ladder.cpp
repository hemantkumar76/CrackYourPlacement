class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // WordList ko unordered_set me convert karenge taaki fast lookup ho sake
        unordered_set<string> dict(wordList.begin(), wordList.end());
        
        // BFS ke liye ek queue banayenge aur usme initial word ko daalenge
        queue<string> todo;
        todo.push(beginWord);
        
        // Ladder ka initial level 1 set karenge
        int ladder = 1;
        
        // Jab tak queue khaali nahi hoti, tab tak loop chalayenge
        while (!todo.empty()) {
            // Har level ke words ka size nikalenge
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                // Queue ke front se current word ko nikalenge
                string word = todo.front();
                todo.pop();
                
                // Agar current word endWord ke barabar ho jaye, to ladder return karenge
                if (word == endWord) {
                    return ladder;
                }
                
                // Visited word ko dict se hata denge
                dict.erase(word);
                
                // Har letter ko replace karne ke liye loop chalayenge
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j]; // Original character ko store karenge
                    
                    // Har character 'a' se 'z' tak try karenge
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        
                        // Agar word dict me milta hai to usse queue me push karenge
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                    }
                    
                    // Word ko original state me wapas le aayenge
                    word[j] = c;
                }
            }
            // Har level ke baad ladder ko increment karenge
            ladder++;
        }
        
        // Agar endWord nahi milta to 0 return karenge
        return 0;
    }
};
