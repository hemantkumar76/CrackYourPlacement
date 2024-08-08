class Solution {
public:
    TreeNode *first, *second, *prev;

    // Inorder traversal karte hain tree ko
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);

        // Agar prev node ka value root node se bada hai, to first aur second nodes set karte hain
        if (prev && prev->val > root->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = second = prev = NULL;

        // Inorder traversal karte hain tree ko
        inorder(root);

        // first aur second nodes ke values swap karte hain
        swap(first->val, second->val);
    }
};
