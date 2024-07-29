class Solution {
public:
    Node* copyRandomList(Node* head) {
        // agar head null hai to null return karte hain
        if (head == NULL) return NULL;
        
        // pehle, hum har node ke copy banate hain aur usko original node ke next mein dalte hain
        Node* node = head;
        while (node != NULL) {
            Node* copy = new Node(node->val);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        
        // phir, hum har copy node ke random pointer set karte hain
        node = head;
        while (node != NULL) {
            if (node->random != NULL) {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }
        
        // last mein, hum original list aur copy list ko separate karte hain
        node = head;
        Node* copyHead = head->next;
        while (node != NULL) {
            Node* copy = node->next;
            node->next = copy->next;
            if (copy->next != NULL) {
                copy->next = copy->next->next;
            }
            node = node->next;
        }
        
        // copy list ka head return karte hain
        return copyHead;
    }
};
