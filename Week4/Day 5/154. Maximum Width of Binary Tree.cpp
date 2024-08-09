class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        // Agar root null hai toh return kar do
        if (root == nullptr) 
            return 0;
        
        // Yeh maximum width ko track karega
        int maxWidth = 0; 

        // Yeh queue har level ke nodes ko track karegi
        // Har node ke saath uska relative position bhi store karenge
        queue<pair<TreeNode*, int>> q; 

        // Root node ko queue mein dalte hai with position 0
        q.push({root, 0}); 

        // Jab tak queue khali nahi hoti
        while (!q.empty()) { 
            // Is level ke nodes ki sankhya
            int size = q.size(); 

            // Is level ke leftmost node ka position
            int left = q.front().second; 

            // Har node ke liye is level mein
            for (int i = 0; i < size; i++) { 
                // Current node
                auto node = q.front().first; 

                // Current node ka relative position
                int relativePosition = q.front().second - left; 

                // Current node ko queue se hatao
                q.pop(); 

                // Maximum width ko update karte hai  if necessary
                maxWidth = max(maxWidth, relativePosition + 1); 

                // Agar left child hai toh queue mein dalte hai
                if (node->left) 
                    q.push({node->left, 2 * relativePosition}); 

                // Agar right child hai toh queue mein dalte hai
                if (node->right) 
                    q.push({node->right, 2 * relativePosition + 1}); 
            }
        }

        // Maximum width return karte hai 
        return maxWidth; 
    }
};
