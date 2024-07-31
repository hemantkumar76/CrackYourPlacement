class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // ek dummy node banate hain jiska next head hoga
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // do pointers banate hain, first aur second, dono ko dummy par set karte hain
        ListNode* first = dummy;
        ListNode* second = dummy;
        
        // first ko n+1 steps aage move karte hain
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }
        
        // jab tak first null nahi ho jata, first aur second ko ek step aage move karte hain
        while (first != NULL) {
            first = first->next;
            second = second->next;
        }
        
        // second ke next node ko delete karte hain
        second->next = second->next->next;
        
        // dummy->next return karte hain jo new head hoga
        return dummy->next;
    }
};
