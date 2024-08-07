class BSTIterator {
    stack<TreeNode*> s; // Ek stack banate hain nodes ke liye
public:
    // Constructor mein, hum leftmost node tak traverse karte hain
    // Aur har node ko stack mein push karte hain
    BSTIterator(TreeNode* root) {
        while(root != NULL) {
            s.push(root);
            root = root->left;
        }
    }
    
    // next function mein, hum stack ka top element pop karte hain
    // Aur uske right child ko stack mein push karte hain
    // Yeh function stack ke top element ko return karta hai
    int next() {
        TreeNode* top = s.top();
        s.pop();
        TreeNode* right = top->right;
        while(right != NULL) {
            s.push(right);
            right = right->left;
        }
        return top->val;
    }
    
    // nxt function check karta hai ki stack khali hai ya nahi
    // Agar stack khali hai, toh return false
    // Nahi toh, return true
    bool hasNext() {
        return !s.empty();
    }
};
