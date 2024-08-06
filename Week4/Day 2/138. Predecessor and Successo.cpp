class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // curr ko root se initialize karte hain
        Node* curr=root;

        // Jab tak curr NULL nahi ho jata
        while(curr!=NULL){
            // Agar curr ka key key se bada ya barabar hai
            // Toh curr ko uske left child se update karte hain
            if(curr->key>=key){
                curr=curr->left;
            }
            // Nahi toh, pre ko curr se update karte hain
            // Aur curr ko uske right child se update karte hain
            else{
                pre=curr;
                curr=curr->right;
            }
        }

        // curr2 ko root se initialize karte hain
        Node* curr2=root;

        // Jab tak curr2 NULL nahi ho jata
        while(curr2!=NULL){
            // Agar curr2 ka key key se bada hai
            // Toh suc ko curr2 se update karte hain
            // Aur curr2 ko uske left child se update karte hain
            if(curr2->key>key){
                suc=curr2;
                curr2=curr2->left;
            }
            // Nahi toh, curr2 ko uske right child se update karte hain
            else{
                curr2=curr2->right;
            }
        }
    }
};
