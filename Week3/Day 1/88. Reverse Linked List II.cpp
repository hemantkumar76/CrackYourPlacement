class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // agar head null hai ya left aur right same hain to head return karte hain
        if (head == NULL || left == right) return head;
        
        // ek dummy node banate hain jiska next head hoga
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // pre node ko find karte hain jo reverse part se pehle aata hain
        ListNode* pre = dummy;
        for (int i = 1; i < left; i++) {
            pre = pre->next;
        }
        
        // start node ko find karte hain jo reverse hona start hoga
        ListNode* start = pre->next;
        // then node ko find karte hain jo start ke next hain
        ListNode* then = start->next;
        
        // reverse part ko reverse karte hain
        for (int i = left; i < right; i++) {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }
        
        // dummy->next return karte hain jo new head hoga
        return dummy->next;
    }
};
