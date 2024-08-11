#include <bits/stdc++.h>
using namespace std;

// utility function jo print karta hai vector ke contents
// index i se leke uske end tak
void printVector(const vector<int>& v, int i)
{
    for (int j = i; j < v.size(); j++)
        cout << v[j] << " ";
    cout << endl;
}

// binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

// Ye function print karta hai sab paths jinka sum k hai
void printKPathUtil(Node* root, vector<int>& path, int k)
{
    // empty node
    if (!root)
        return;

    // add karo current node ko path me
    path.push_back(root->data);

    // check karo kya koi k sum path hai
    // left sub-tree me.
    printKPathUtil(root->left, path, k);

    // check karo kya koi k sum path hai
    // right sub-tree me.
    printKPathUtil(root->right, path, k);

    // check karo kya koi k sum path hai jo
    // terminate hota hai is node pe
    // Traverse karo pura path kyunki
    // negative elements bhi ho sakte hain
    int f = 0;
    for (int j = path.size() - 1; j >= 0; j--) {
        f += path[j];

        // Agar path sum hai k, print karo path
        if (f == k)
            printVector(path, j);
    }

    // Remove karo current element ko path se
    path.pop_back();
}

// Ek wrapper over printKPathUtil()
void printKPath(Node* root, int k)
{
    vector<int> path;
    printKPathUtil(root, path, k);
}

// Driver code
int main()
{
    Node* root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);

    return 0;
}
