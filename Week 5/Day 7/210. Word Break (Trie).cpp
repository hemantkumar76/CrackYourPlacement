class Solution{
public:
    TrieNode* root;
    Solution() {
        root = new TrieNode();
    }
    
    // shabd ko trie me add karna
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == NULL)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEndOfWord = true;
    }
    
    // A : given string to search
    // B : vector of available strings
    int wordBreak(string A, vector<string> &B) {
        // sabhi shabd ko trie me add karna
        for (string word : B) {
            addWord(word);
        }
        
        int n = A.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        // dynamic programming ka use karke check karna ki kya string A ko segment kiya ja sakta hai
        for (int i = 1; i <= n; i++) {
            TrieNode* node = root;
            for (int j = i; j >= 1; j--) {
                char c = A[j - 1];
                if (node->children[c - 'a'] == NULL)
                    break;
                node = node->children[c - 'a'];
                if (node->isEndOfWord && dp[j - 1]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        // agar string A ko segment kiya ja sakta hai to 1 return karna, nahi to 0
        return dp[n] ? 1 : 0;
    }
};
