class Solution {
public:
    // Helper function jo maximum path sum calculate karti hai
    int fun(TreeNode* root, int & maxi) {
        // Agar root null hai toh 0 return kar do
        if (root == NULL) {
            return 0;
        }
        // Left subtree ka maximum path sum calculate karte hain
        int left = max(0, fun(root->left, maxi));
        // Right subtree ka maximum path sum calculate karte hain
        int right = max(0, fun(root->right, maxi));
        // Maximum path sum update karte hain
        maxi = max(maxi, root->val + left + right);
        // Maximum path sum return karte hain
        return (root->val + max(left, right));
    }
    // Function jo tree ka maximum path sum calculate karti hai
    int maxPathSum(TreeNode* root) { 
        // Maximum path sum initialize karte hain
        int maxi = INT_MIN;
        // Helper function call karte hain
        fun(root, maxi); 
        // Maximum path sum return karte hain
        return maxi;
    }
};
