class Solution {
public:
    // Function jo tree banata hai preorder aur postorder traversals se
    TreeNode* build(vector<int>& pre, int prestart, int preend,
               vector<int>& post, int poststart, int postend) {

        // Agar start index end index se bada hai, to NULL return karo
        if(prestart > preend) return NULL;

        // Naya node banate hain preorder traversal ke pehle element se
        int k = pre[prestart];
        TreeNode* root = new TreeNode(k);  

        // Agar start index aur end index same hain, to node return karo
        if(prestart == preend) return root;

        // Preorder traversal mein left subtree ka root dhundte hain
        int left_root = pre[prestart + 1];

        // Postorder traversal mein left root ka index dhundte hain
        int i = poststart;
        while(i <= postend) {
            if(post[i] == left_root) break;
            i++;
        }  

        // Left subtree ki length calculate karte hain
        int l = i - poststart + 1;

        // Recursively left aur right subtrees banate hain
        root->left = build(pre, prestart + 1, prestart + l, post, poststart, i);
        root->right = build(pre, prestart + l + 1, preend, post, i + 1, postend - 1);

        // Tree ka root return karte hain
        return root;
    }

    // Function jo tree banata hai preorder aur postorder traversals se
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        return build(pre, 0, n - 1, post, 0, n - 1);
    }
};
