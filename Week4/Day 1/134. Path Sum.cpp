class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: agar root null hai, toh false return karte hain
        if (root == nullptr) {
            return false;
        }

        // Agar root leaf node hai, toh hum check karte hain ki kya root ki value target sum ke equal hai
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        // Nahi toh, hum left subtree aur right subtree mein DFS karte hain
        // Hum target sum se root ki value subtract karte hain
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
