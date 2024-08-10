class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Map jo vertical order, level order, aur node values ko store karta hai
        map < int , map < int , multiset < int >>> lol;
        // Queue jo BFS ke liye use hota hai
        queue < pair < TreeNode* , pair < int , int >>> q;
        vector < vector <int >> ans;
        // Agar root null hai toh empty answer return kar do
        if(root == NULL) return ans;
        // Root node ko queue me daalte hain
        q.push({root , {1,1}});
        while(!q.empty()){
            auto top = q.front();
            TreeNode * temp = top.first;
            int vertical = top.second.first;
            int level = top.second.second;
            // Current node ki value map me daalte hain
            lol[vertical][level].insert(temp -> val);
            // Agar left child hai toh queue me daalte hain
            if(temp -> left != NULL){
                q.push({temp -> left , {vertical - 1 , level + 1} });
            }
            // Agar right child hai toh queue me daalte hain
            if(temp -> right != NULL){
                q.push({temp -> right , {vertical + 1 , level + 1} });
            }
        }
        // Map me se values ko answer vector me daalte hain
        for(auto it : lol){
            vector < int > res;
            for(auto j : it.second){
                res.insert(res.end() , j.second.begin() , j.second.end());
            }
            ans.push_back(res);
        }
        // Answer return karte hain
        return ans;
    }
};
