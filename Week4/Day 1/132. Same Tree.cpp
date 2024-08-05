class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base case: agar dono nodes null hain, toh trees same hain
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // Agar sirf ek node null hai, toh trees same nahi hain
        // Ya agar dono nodes ki values same nahi hain, toh trees same nahi hain
        if (p == nullptr || q == nullptr || p->val != q->val) {
            return false;
        }

        // Left subtree aur right subtree dono same hone chahiye
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
