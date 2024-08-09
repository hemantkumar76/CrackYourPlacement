class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // Yeh variable kth smallest element ko track karega
        int result;

        // Yeh function tree ko in-order traverse karega
        // Aur jab kth node visit karega, toh result ko update karega
        // Aur true return karega to indicate ki kth node mil gaya
        function<bool(TreeNode*)> inorder = [&](TreeNode* node) {
            // Agar node null hai, toh false return karte hai 
            if (node == nullptr)
                return false;

            // Pehle left subtree ko traverse karte hai 
            if (inorder(node->left))
                return true;

            // Agar yeh kth node hai, toh result ko update karte hai 
            // Aur true return karte hai 
            if (--k == 0) {
                result = node->val;
                return true;
            }

            // Phir right subtree ko traverse karte hai 
            return inorder(node->right);
        };

        // Tree ko in-order traverse karte hai 
        inorder(root);

        // Kth smallest element return karte hai 
        return result;
    }
};
