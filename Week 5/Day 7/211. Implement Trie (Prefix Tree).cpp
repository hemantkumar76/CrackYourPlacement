class TrieNode {
public:
    // har node ke liye 26 pointers for each english alphabet
    TrieNode* children[26];
    // isEndOfWord will be true if the node represents the end of word
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    // shabd ko trie me insert karna
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == NULL)
                node->children[c - 'a'] = new TrieNode();
            node = node->children[c - 'a'];
        }
        node->isEndOfWord = true;
    }
    
    // shabd ko trie me search karna
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        return node->isEndOfWord;
    }
    
    // kisi bhi shabd ko trie me search karna jo prefix se start hota hai
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children[c - 'a'] == NULL)
                return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
