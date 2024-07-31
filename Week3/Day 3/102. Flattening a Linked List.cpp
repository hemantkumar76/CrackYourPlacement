Node *flatten(Node *root) {
    // Root se start karke, har node ko traverse karenge
    Node *temp = root;
    // Sabhi nodes ke data ko ek vector mein store karenge
    vector<int> arr;
    
    // Jab tak temp null nahi hota, tab tak loop chalayenge
    while(temp){
        // Temp node ke data ko vector mein push karenge
        arr.push_back(temp->data);
        // Temp node ke child nodes ko traverse karenge
        Node *child = temp->bottom;
        while(child){
            // Child node ke data ko vector mein push karenge
            arr.push_back(child->data);
            // Child pointer ko next node pe move karenge
            child = child->bottom;
        }
        // Temp pointer ko next node pe move karenge
        temp = temp->next;
    }
    
    // Vector ko sort karenge
    sort(arr.begin(), arr.end());
    
    // Ek dummy node banayenge
    Node *dummy = new Node(-1);
    // Dummy node ke bottom mein sorted vector ka pehla element dalenge
    dummy->bottom = new Node(arr[0]);
    temp = dummy->bottom;
    // Sorted vector ke baaki elements ko linked list mein add karenge
    for(int i=1; i<arr.size(); i++){
        temp->bottom = new Node(arr[i]);
        temp = temp->bottom;
    }
    
    // Dummy node ke bottom ko return karenge, jo ki flattened linked list ka head hoga
    return dummy->bottom;
}
