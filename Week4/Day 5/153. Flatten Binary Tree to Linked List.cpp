class Solution {
public:
    TreeNode* prev = nullptr; // yeh previous node ko track karega

    void flatten(TreeNode* root) {
        if (root == nullptr) // agar root null hai toh return kar do
            return;
        
        flatten(root->right); // pehle right subtree ko flatten karte hai
        flatten(root->left);  // phir left subtree ko flatten karte hai

        // ab root node ko adjust karte hai
        root->right = prev; // right pointer ko previous node pe set karte hai
        root->left = nullptr; // left pointer ko nullify karte hai

        prev = root; // ab current node ko previous node banado for the next iteration
    }
};
