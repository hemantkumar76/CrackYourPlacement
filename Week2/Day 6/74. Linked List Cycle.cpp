class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        if(head == NULL){
            return 0;
        }
        if(head -> next == NULL){
            return 0;
        }
        while(fast != NULL && slow != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
                slow = slow -> next;
            }
            if(fast == slow){
                return 1;
            }
        }
        return 0;
        
    }
};
