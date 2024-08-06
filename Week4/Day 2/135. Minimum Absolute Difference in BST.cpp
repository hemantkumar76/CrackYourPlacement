class Solution {
public:
    int diff_hai = INT_MAX;
    TreeNode* prev = NULL;

    int getMinimumDifference(TreeNode* root) {
        // Agar tree khali hai toh 0 return karte hain
        if (root == NULL) return diff_hai;

        // Pehle left subtree pe call karte hain
        getMinimumDifference(root->left);

        // Agar prev NULL nahi hai toh current node aur previous node ke beech ka difference calculate karte hain
        // Aur agar yeh difference diff se chota hai toh diff update karte hain
        if (prev != NULL) diff_hai = min(diff_hai, root->val - prev->val);

        // prev ko current node se update karte hain
        prev = root;

        // Fir right subtree pe call karte hain
        getMinimumDifference(root->right);

        // Last mein, minimum difference return karte hain
        return diff_hai;
    }
};
