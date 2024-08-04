class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Agar tree khali hai, toh sum 0 hoga
        if (root == nullptr) {
            return 0;
        }

        // Agar root ka value `low` se kam hai, toh hum right subtree mein `low` se `high` tak ke values ka sum calculate karte hain
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        // Agar root ka value `high` se zyada hai, toh hum left subtree mein `low` se `high` tak ke values ka sum calculate karte hain
        else if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }
        // Agar root ka value `low` aur `high` ke beech mein hai, toh hum us value ko add karte hain left aur right subtree mein `low` se `high` tak ke values ka sum mein
        else {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
    }
};
