class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // ek naya ListNode banate hain jisme hum result store karenge
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        
        // jab tak dono linked lists ke end tak nahi pahunch jaate, tab tak loop chalate hain
        while(l1 != nullptr || l2 != nullptr || carry){
            int sum = 0;
            // agar l1 null nahi hai to uska value add karte hain sum mein
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            
            // agar l2 null nahi hai to uska value add karte hain sum mein
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }
            
            // carry ko bhi add karte hain sum mein
            sum += carry;
            // agar sum 10 se bada hai to carry 1 set karte hain
            carry = sum / 10;
            
            // naye node mein sum ka last digit store karte hain
            ListNode* node = new ListNode(sum % 10);
            // is node ko temp ke next mein add karte hain
            temp->next = node;
            // temp ko update karte hain next node ke liye
            temp = temp->next;
        }
        
        // hum dummy->next return karte hain kyun ki dummy mein humne kuch store nahi kiya
        return dummy->next;
    }
};
