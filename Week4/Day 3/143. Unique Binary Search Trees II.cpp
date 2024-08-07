class Solution {
public:
    // Helper function jo start se end tak ke numbers ke liye saare unique BSTs generate karta hai
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> list;
        // Agar start bada hai end se, toh NULL tree return karte hain
        if (start > end) {
            list.push_back(NULL);
            return list;
        }
        // Har number ko root banake, uske left aur right subtrees generate karte hain
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);
            // Har left subtree aur right subtree ke combination ke liye ek new tree banate hain
            for (TreeNode* l : left) {
                for (TreeNode* r : right) {
                    TreeNode* curr = new TreeNode(i);
                    curr->left = l;
                    curr->right = r;
                    list.push_back(curr);
                }
            }
        }
        return list;
    }

    vector<TreeNode*> generateTrees(int n) {
        // Agar n 0 hai toh khali vector return karte hain
        if (n == 0) return vector<TreeNode*>();
        // Nahi toh, helper function se saare unique BSTs generate karte hain
        return generate(1, n);
    }
};
