class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
        // Agar tree khali hai toh 0 return karte hain
        if (root == NULL) 
        {
            return 0;
        }

        // Agar current node ek leaf node hai aur yeh left child hai toh iska value return karte hain
        if (root->left == NULL && root->right == NULL && isLeft) return root->val;

        // Nahi toh, left aur right subtree ka sum return karte hain
        // Left subtree ke liye 'isLeft' true hai aur right subtree ke liye 'isLeft' false hai
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
