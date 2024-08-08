class Solution {
public:
    int pathSum(TreeNode* root, int sum_target) {
        // Agar root null hai toh 0 return karte hain kyunki koi path exist nahi karta
        if (root == nullptr) {
            return 0;
        }

        // Root se start hone wale paths, left subtree se start hone wale paths aur right subtree se start hone wale paths ka sum calculate karte hain
        return pathSumFrom(root, sum_target) + pathSum(root->left, sum_target) + pathSum(root->right, sum_target);
    }

private:
    int pathSumFrom(TreeNode* node, int sum_target) {
        // Agar current node null hai toh 0 return karte hain
        if (node == nullptr) {
            return 0;
        }

        // Agar current node ki value target sum ke equal hai toh 1 add karte hain result me, otherwise 0 add karte hain
        int result = node->val == sum_target ? 1 : 0;

        // Left aur right subtree me se paths find karte hain jinka sum target sum se equal hai
        result += pathSumFrom(node->left, sum_target - node->val);
        result += pathSumFrom(node->right, sum_target - node->val);

        // Final result return karte hain
        return result;
    }
};
