class Solution
{  
private:
    // Helper function jo DLL banata hai
    void dll(Node* root, Node* arr[2]){
        // Agar root null hai toh return kar do
        if(root==nullptr)
        return ;
        
        // Left subtree pe recursive call karte hain
        dll(root->left, arr);
        
        // Agar yeh pehla node hai toh arr[1] aur arr[0] dono ko root set karte hain
        if(arr[1]==nullptr){
            arr[1]=root;
            arr[0]=root;
        }
        else {
            // Nahi toh, current node ko previous node ke right child banate hain
            // aur previous node ko current node ke left child banate hain
            root->left = arr[0];
            arr[0]->right = root;
            
            // arr[0] ko current node set karte hain
            arr[0] = root;
        }
        
        // Right subtree pe recursive call karte hain
        dll(root->right, arr);
    } 

public:    
    // Function jo BST ko DLL me convert karta hai
    Node* bToDLL(Node* root)
    {
        // arr[0] previous node store karta hai, aur arr[1] DLL ka head node store karta hai
        Node* arr[2] = {nullptr, nullptr};
        
        // Helper function call karte hain
        dll(root, arr);
        
        // DLL ka head node return karte hain
        return arr[1];
    }
};
