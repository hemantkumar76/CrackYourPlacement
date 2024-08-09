class Solution{
    public:
    
    
    Node * LCA(Node * root, int a, int b){
        if(root == NULL || root->data == a || root->data == b){
            return root;
        }
        
        Node * left = LCA(root->left,a,b);
        Node * right = LCA(root->right,a,b);
        
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else{
            return root;
        }
    }
    
    int dist(Node * root, int a,int d){
        
        if(root == NULL){
            return 0;
        }
        
        if(root->data == a){
            return d;
        }
        
        int left = dist(root->left,a,d+1);
        int right = dist(root->right,a,d+1);
        
        return max(left,right);
    }
    int findDist(Node* root, int a, int b) {
        
        
        Node* lca = LCA(root,a,b);
        
        int dista = dist(lca,a,0);
        int distb = dist(lca,b,0);
        
        return dista+distb;
    }
};
