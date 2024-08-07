class Solution {
public:
    // Helper function jo check karta hai ki tree BST hai ya nahi
    // Isme hum minimum aur maximum values pass karte hain
    bool isValidBST(TreeNode* root, long long minVal, long long maxVal) {
        // Agar root null hai, toh return true
        if (root == NULL) return true;
        // Agar root ki value min ya max se bahar hai, toh return false
        if (root->val <= minVal || root->val >= maxVal) return false;
        // Nahi toh, left aur right subtrees check karte hain
        return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        // Helper function call karte hain maximum aur minimum integer values ke saath
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};
