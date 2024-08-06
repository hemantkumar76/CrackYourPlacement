class Solution{
  public:
    bool helper(Node* root,set<int>st)
    {
        // Agar root NULL hai toh false return karte hain
        if(root==NULL) return false;

        // Agar root ek leaf node hai
        // Aur uska data - 1 aur data + 1 dono set mein hain
        // Toh true return karte hain
        if(root->left==NULL && root->right==NULL)
        {
            if(st.find(root->data-1)!=st.end() && st.find(root->data+1)!=st.end()) 
                return true;
        }

        // Root ka data set mein insert karte hain
        st.insert(root->data);

        // Left subtree ya right subtree mein dead end hai ya nahi check karte hain
        return helper(root->left,st) || helper(root->right,st);
    }

    bool isDeadEnd(Node *root)
    {
        // Ek set banate hain aur usme 0 insert karte hain
        set<int>st;
        st.insert(0);

        // Helper function se check karte hain ki tree mein dead end hai ya nahi
        return helper(root,st);
    }
};
