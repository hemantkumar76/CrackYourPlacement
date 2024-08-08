class Solution {
public:
    Node* connect(Node* root) {
        // Agar root NULL hai, to NULL return karte hain
        if (!root) return NULL;

        // Queue mein root node daalte hain
        queue<Node*> q;
        q.push(root);

        // Jab tak queue khali nahi hoti, tab tak loop chalate hain
        while (!q.empty()) {
            // Current level ke nodes ki count nikalte hain
            int size = q.size();

            // Current level ke har node ke liye
            for (int i = 0; i < size; i++) {
                // Queue se node nikalte hain
                Node* node = q.front();
                q.pop();

                // Agar yeh node last node nahi hai, to iske 'next' pointer ko queue ke agle node se connect karte hain
                if (i < size - 1) {
                    node->next = q.front();
                }

                // Node ke left aur right child ko queue mein daalte hain
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return root;
    }
};
