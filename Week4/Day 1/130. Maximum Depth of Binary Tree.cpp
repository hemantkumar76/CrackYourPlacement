class Solution {
public:
    int maxDepth(TreeNode* root) {
        // Base case: agar root null hai, toh depth 0 hai
        if (root == nullptr) {
            return 0;
        }

        // Left subtree ka maximum depth find karte hain
        int leftDepth = maxDepth(root->left);

        // Right subtree ka maximum depth find karte hain
        int rightDepth = maxDepth(root->right);

        // Maximum depth yeh hoga: 1 (for the current node) + maximum of left and right depths
        return 1 + max(leftDepth, rightDepth);
    }
};
