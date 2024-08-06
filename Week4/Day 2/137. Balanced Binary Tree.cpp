class Solution {
public:
    // Helper function jo tree ki height calculate karta hai
    int height(TreeNode* root) {
        // Agar tree khali hai toh height 0 hai
        if (root == NULL) return 0;

        // Nahi toh, height 1 plus maximum height of left and right subtrees hai
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        // Agar tree khali hai toh woh balanced hai
        if (root == NULL) return true;

        // Tree balanced hai agar left subtree aur right subtree ki height ka difference 1 se kam hai
        // Aur left subtree aur right subtree dono balanced hain
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};
