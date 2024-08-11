class Codec {
public:

    // Ek tree ko ek single string me encode karta hai.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "null ";
        }
        // Node ki value ko string me convert karo, phir left aur right subtree ko recursively serialize karo.
        return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }

    // Apke encoded data ko tree me decode karta hai.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }

private:
    // Helper function jo istringstream object se data read karke TreeNode banata hai.
    TreeNode* deserializeHelper(istringstream& iss) {
        string val;
        iss >> val;
        if (val == "null") {
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(iss);
        node->right = deserializeHelper(iss);
        return node;
    }
};
