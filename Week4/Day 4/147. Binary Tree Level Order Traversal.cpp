class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Agar root null hai toh khali vector return karo
        if (root == nullptr) {
            return {};
        }

        // Ek queue banate hain jisme hum nodes store karenge
        queue<TreeNode*> q;
        // Root node ko queue me daalte hain
        q.push(root);

        // Ek vector banate hain jisme hum final result store karenge
        vector<vector<int>> result;

        // Jab tak queue khali nahi hoti tab tak loop chalate hain
        while (!q.empty()) {
            // Current level ke nodes ki count store karte hain
            int levelSize = q.size();

            // Ek vector banate hain jisme hum current level ke nodes store karenge
            vector<int> currentLevel;

            // Current level ke har node ke liye loop chalate hain
            for (int i = 0; i < levelSize; i++) {
                // Queue se ek node nikalte hain
                TreeNode* node = q.front();
                q.pop();

                // Node ki value ko current level vector me daalte hain
                currentLevel.push_back(node->val);

                // Agar node ka left child exist karta hai toh use queue me daalte hain
                if (node->left != nullptr) {
                    q.push(node->left);
                }

                // Agar node ka right child exist karta hai toh use queue me daalte hain
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Current level vector ko result vector me daalte hain
            result.push_back(currentLevel);
        }

        // Final result return karte hain
        return result;
    }
};
