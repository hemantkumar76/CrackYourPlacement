class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // Agar dono trees khali hain, toh woh ek dusre ke subtree hain
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        // Agar ek tree khali hai aur dusra nahi, toh woh ek dusre ke subtree nahi hain
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        // Agar root ke value aur structure match kar rahe hain subRoot ke saath, toh true return karte hain
        // Nahi toh hum root ke left ya right subtree mein subRoot dhundte hain
        return isSame(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        // Agar dono trees khali hain, toh woh same hain
        if (root == nullptr && subRoot == nullptr) {
            return true;
        }
        // Agar ek tree khali hai aur dusra nahi, toh woh same nahi hain
        if (root == nullptr || subRoot == nullptr) {
            return false;
        }
        // Agar dono trees ke roots ke values same hain aur unke left aur right subtrees bhi same hain, toh woh same hain
        return root->val == subRoot->val && isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
};
