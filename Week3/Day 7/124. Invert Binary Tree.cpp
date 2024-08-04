class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Agar tree khali hai, toh kuch nahi karna hai
        if (root == nullptr) {
            return nullptr;
        }

        // Pehle left aur right child ko swap karte hain
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Phir hum recursively left aur right subtree ko invert karte hain
        invertTree(root->left);
        invertTree(root->right);

        // Finally, hum inverted tree ka root return karte hain
        return root;
    }
};
