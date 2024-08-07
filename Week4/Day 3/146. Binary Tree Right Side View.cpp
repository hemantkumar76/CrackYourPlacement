class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (root == NULL) return {};  // Agar root null hai toh khali vector return karte hain

        vector<int> rightView;  // Right view store karne ke liye vector
        queue<TreeNode*> q;  // BFS ke liye queue
        q.push(root);  // Root ko queue mein daalte hain

        while (!q.empty()) {  // Jab tak queue khali nahi hoti
            int size = q.size();  // Current level ke nodes ki count
            for (int i = 0; i < size; i++) {  // Har node ke liye
                TreeNode* node = q.front();  // Queue se node nikalte hain
                q.pop();
                if (i == size - 1)  // Agar yeh last node hai toh usko right view mein daalte hain
                    rightView.push_back(node->val);
                if (node->left) q.push(node->left);  // Left child ko queue mein daalte hain
                if (node->right) q.push(node->right);  // Right child ko queue mein daalte hain
            }
        }

        return rightView;  // Right view return karte hain
    }
};
