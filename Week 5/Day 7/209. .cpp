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

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
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
    
    // shabd ko trie me search karna
    bool search(string word) {
        return searchInNode(word, root);
    }
    
    bool searchInNode(string word, TrieNode* node) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (node->children[c - 'a'] == NULL) 
                    return false;
                node = node->children[c - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (node->children[j] != NULL && searchInNode(word.substr(i + 1), node->children[j]))
                        return true;
                }
                return false;
            }
        }
        return node->isEndOfWord;
    }
};
