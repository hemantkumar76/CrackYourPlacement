class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Agar root null hai, toh khali vector return karte hai 
        if (root == nullptr)
            return {};

        // Yeh vector har level ke nodes ke values ko store karega
        vector<vector<int>> levels;

        // Yeh queue har level ke nodes ko store karega
        queue<TreeNode*> q;
        q.push(root); // Root node ko queue mein dalte hai 

        // Jab tak queue khali nahi hoti
        while (!q.empty()) {
            // Is level ke nodes ki sankhya
            int size = q.size();

            // Yeh vector is level ke nodes ke values ko store karega
            vector<int> level;

            // Har node ke liye is level mein
            for (int i = 0; i < size; i++) {
                // Current node
                TreeNode* node = q.front();
                q.pop(); // Current node ko queue se hatao

                // Current node ke value ko level vector mein dalte hai 
                level.push_back(node->val);

                // Agar left child hai toh queue mein dalte hai 
                if (node->left)
                    q.push(node->left);

                // Agar right child hai toh queue mein dalte hai 
                if (node->right)
                    q.push(node->right);
            }

            // Agar level number odd hai, toh level vector ko reverse karte hai 
            if (levels.size() % 2 == 1)
                reverse(level.begin(), level.end());

            // Level vector ko levels vector mein dalte hai 
            levels.push_back(level);
        }

        // Levels vector return karte hai 
        return levels;
    }
};
