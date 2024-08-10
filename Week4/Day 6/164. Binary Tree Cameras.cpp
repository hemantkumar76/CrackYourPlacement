/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total = 0; // Total cameras ki count

    int minCameraCover(TreeNode* root) {
        int val =  postorder(root); // Postorder traversal se camera ki zarurat check karte hain
        if(val==1) total++; // Agar root node ko monitor karne ki zarurat hai toh camera add karte hain

        return total; // Total cameras return karte hain
    }

    // Postorder traversal function
    int postorder(TreeNode* root){
        if(!root) return 3; // Agar node null hai toh 3 return karte hain

        int left = postorder(root->left); // Left subtree ki value calculate karte hain
        int right  = postorder(root->right); // Right subtree ki value calculate karte hain

        // Agar left ya right node ko monitor karne ki zarurat hai toh camera add karte hain
        if(left==1||right==1){
            total++;
            return 2;
        }
        // Agar dono subtrees monitored hain toh current node ko monitor karne ki zarurat hai
        if(left==3&&right==3){
            return 1;
        }
        // Agar koi bhi subtree camera se monitored hai toh current node monitored hai
        if(left==2||right==2){
            return 3;
        }
        return 0;
    }
};
