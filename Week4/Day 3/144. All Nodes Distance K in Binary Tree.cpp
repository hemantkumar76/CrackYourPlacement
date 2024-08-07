class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;  // Node se uske parent tak ka map
    vector<int> ans;

    void findParents(TreeNode* node, TreeNode* par) {
        if (node != NULL) {
            parent[node] = par;
            findParents(node->left, node);
            findParents(node->right, node);
        }
    }

    void findAns(TreeNode* node, TreeNode* prev, int k) {
        if (node == NULL)
            return;
        if (k == 0) {
            ans.push_back(node->val);
            return;
        }
        if (node->left != prev)
            findAns(node->left, node, k - 1);
        if (node->right != prev)
            findAns(node->right, node, k - 1);
        if (parent[node] != prev)
            findAns(parent[node], node, k - 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root, NULL);
        findAns(target, NULL, k);
        return ans;
    }
};
