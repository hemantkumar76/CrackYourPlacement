class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        // Base case: agar root1 null hai, toh hum root2 return kar dete hain
        if (root1 == nullptr) {
            return root2;
        }
        // Base case: agar root2 null hai, toh hum root1 return kar dete hain
        if (root2 == nullptr) {
            return root1;
        }

        // Dono nodes ki values ko add karke naya node banate hain
        TreeNode* merged = new TreeNode(root1->val + root2->val);

        // Left subtree ke liye recursive call karte hain
        merged->left = mergeTrees(root1->left, root2->left);

        // Right subtree ke liye recursive call karte hain
        merged->right = mergeTrees(root1->right, root2->right);

        // Merged tree ka root return karte hain
        return merged;
    }
};
