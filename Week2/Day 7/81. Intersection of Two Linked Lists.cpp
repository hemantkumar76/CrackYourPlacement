class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Do pointers ko initialize karte hain
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        
        // Jab tak dono pointers same nahi ho jate, tab tak loop chalate hain
        while(ptr1 != ptr2){
            // Agar ptr1 null hai, toh use headB se point karate hain
            if(ptr1 == NULL){
                ptr1 = headB;
            }
            // Agar ptr1 null nahi hai, toh use next node pe move karate hain
            else{
                ptr1 = ptr1 -> next;
            }
            // Agar ptr2 null hai, toh use headA se point karate hain
            if(ptr2 == NULL){
                ptr2 = headA;
            }
            // Agar ptr2 null nahi hai, toh use next node pe move karate hain
            else{
                ptr2 = ptr2 -> next;
            }
        }
        // Intersection point return karate hain
        return ptr1;
    }
};
