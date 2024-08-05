class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        // Result vector banate hain jisme hum saare paths store karenge
        vector<string> paths;
        // DFS start karte hain
        dfs(root, "", paths);
        // Saare paths return karte hain
        return paths;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& paths) {
        // Base case: agar node null hai, toh kuch nahi karna hai
        if (node == nullptr) {
            return;
        }

        // Current node ko path mein add karte hain
        path += to_string(node->val);

        // Agar current node leaf node hai, toh hum path ko result mein add kar dete hain
        if (node->left == nullptr && node->right == nullptr) {
            paths.push_back(path);
        } else {
            // Nahi toh, hum left aur right child pe DFS karte hain
            // "->" ko path mein add karte hain kyunki hume "1->2->5" format mein paths chahiye
            dfs(node->left, path + "->", paths);
            dfs(node->right, path + "->", paths);
        }
    }
};
