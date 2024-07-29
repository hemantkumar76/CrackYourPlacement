class Solution {
public:
    void reorderList(ListNode* head) {
        // agar head null hai ya sirf ek node hai to return karte hain
        if (!head || !head->next) return;
        
        // slow aur fast pointers banate hain
        ListNode *slow = head, *fast = head;
        
        // slow ko list ke middle mein le jaate hain
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // second half ko reverse karte hain
        ListNode *prev = NULL, *curr = slow->next;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // second half ko disconnect karte hain overflow nhi hoga 
        
        slow->next = NULL;
        
        // first half aur reversed second half ko merge karte hain
        ListNode *first = head, *second = prev;
        while (second) {
            ListNode *next = first->next;
            first->next = second;
            first = second;
            second = next;
        }
    }
};
