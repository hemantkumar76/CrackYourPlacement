class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans_hai;
        if (root == NULL) {

            return ans_hai;
        }
        vector<int> left = inorderTraversal(root->left);
        ans_hai.insert(ans_hai.end(), left.begin(), left.end());
        ans_hai.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        ans_hai.insert(ans_hai.end(), right.begin(), right.end());
        return ans_hai;
    }
};
