class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // Trie Node class banate hain
        struct TrieNode
        {
            unordered_map<char,TrieNode*> child;
            bool isEnd;
            vector<string> suggestions;
        };

        // Trie me word insert karne ka function
        void insert(TrieNode *root, string contact)
        {
            TrieNode *temp = root;
            for(int i=0;i<contact.size();i++)
            {
                char x = contact[i];
                if(temp->child.count(x)==0)
                    temp->child[x] = new TrieNode();
                temp = temp->child[x];
                if(temp->suggestions.size()<3)
                    temp->suggestions.push_back(contact);
            }
            temp->isEnd = 1;
        }

        // Trie me se word search karne ka function
        vector<string> search(TrieNode *root, string query)
        {
            TrieNode *temp = root;
            vector<string> res;
            int f = 0;
            for(int i=0;i<query.size();i++)
            {
                char x = query[i];
                if(temp->child.count(x)==0)
                    return {"0"};
                temp = temp->child[x];
                if(temp->suggestions.size()==0)
                    return {"0"};
                res = temp->suggestions;
            }
            return res;
        }

        // Trie banate hain
        TrieNode *root = new TrieNode();
        for(int i=0;i<n;i++)
            insert(root,contact[i]);
        vector<vector<string>> ans;
        string prefix = "";
        for(int i=0;i<s.size();i++)
        {
            prefix += s[i];
            ans.push_back(search(root,prefix));
        }
        return ans;
    }
};
