class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // pehla element root banate hain
        Node* root = newNode(pre[0]);

        // ek khali stack banate hain aur root ko push karte hain
        Stack* s = createStack(size);
        push(s, root);

        // baaki elements ke liye iterate karte hain
        for (int i = 1; i < size; ++i) {
            Node* temp = NULL;

            // agar current element stack ke top se chota hai toh left child banate hain
            while (!isEmpty(s) && pre[i] > peek(s)->data) {
                temp = pop(s);
            }

            // naya node banate hain
            Node* new_node = newNode(pre[i]);

            // agar temp NULL nahi hai toh right child banate hain
            if (temp != NULL) {
                temp->right = new_node;
            } else { // warna left child banate hain
                if (!isEmpty(s)) {
                    peek(s)->left = new_node;
                }
            }

            // naye node ko push karte hain
            push(s, new_node);
        }

        // root return karte hain
        return root;
    }
};
