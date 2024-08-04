class Solution {
    int lol(TreeNode* root, int& diameter) {
        if (root == NULL) return 0;                        
        int left = lol(root->left, diameter);           
        int right = lol(root->right, diameter);         
        diameter = max(diameter, left + right);          
        return max(left, right) + 1;                   
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;                            
        lol(root, diameter);                      
        return diameter;                           
    }
};
