class Solution {
public:
    Node* flatten(Node* head) {
        // Agar head null hai, toh null return karenge
        if (head == nullptr)
            return nullptr;

        // Ek stack banayenge jisme hum nodes store karenge
        stack<Node*> stk;
        stk.push(head); // Sabse pehle head ko stack mein daalenge

        Node* prev = nullptr; // Yeh previous node ko track karega

        // Jab tak stack khali nahi hota, tab tak loop chalayenge
        while (!stk.empty()) {
            Node* curr = stk.top(); // Stack ke top pe jo node hai usko current
                                    // node banayenge
            stk.pop();              // Aur usko stack se hata denge

            // Agar pehle se koi node hai, toh usko current node se connect
            // karenge
            if (prev) {
                prev->next = curr;
                curr->prev = prev;
            }

            // Agar current node ka next node hai, toh usko stack mein daalenge
            if (curr->next) {
                stk.push(curr->next);
                curr->next =
                    nullptr; // Aur current node ka next pointer null kar denge
            }

            // Agar current node ka child node hai, toh usko bhi stack mein
            // daalenge
            if (curr->child) {
                stk.push(curr->child);
                curr->child =
                    nullptr; // Aur current node ka child pointer null kar denge
            }

            prev = curr; // Ab current node ko previous node banayenge
        }

        return head; // Finally, modified head return karenge
    }
};
