class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // Agar tree khali hai, toh woh symmetric hai
        if (root == nullptr) {
            return true;
        }
        // Nahi toh hum check karte hain ki kya left subtree aur right subtree ek dusre ke mirror hain
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Agar dono subtrees khali hain, toh woh ek dusre ke mirror hain
        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }
        // Agar ek subtree khali hai aur dusra nahi, toh woh ek dusre ke mirror nahi hain
        if (t1 == nullptr || t2 == nullptr) {
            return false;
        }
        // Agar dono subtrees ke roots ke values same hain aur t1 ke left subtree aur t2 ke right subtree ek dusre ke mirror hain
        // aur t1 ke right subtree aur t2 ke left subtree ek dusre ke mirror hain, toh woh ek dusre ke mirror hain
        return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
    }
};
