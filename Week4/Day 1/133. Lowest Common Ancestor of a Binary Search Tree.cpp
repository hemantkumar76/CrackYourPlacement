class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Agar dono nodes root se chote hain, toh LCA left subtree mein hoga
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // Agar dono nodes root se bade hain, toh LCA right subtree mein hoga
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // Agar ek node root se chota hai aur dusra bada hai, toh root hi LCA hoga
        return root;
    }
};
