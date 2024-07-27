class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int total_hai=0;
        while(head!=NULL){
            total_hai=total_hai*2+head->val;
            head=head->next;
        }
        return total_hai;
    }
};
