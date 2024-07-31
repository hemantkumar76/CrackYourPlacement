class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Do naye linked lists banayenge - ek before aur ek after
        // before mein woh nodes honge jo x se chhote hain
        // after mein woh nodes honge jo x se bade ya barabar hain
        ListNode* before_head = new ListNode(0);
        ListNode* before = before_head;
        ListNode* after_head = new ListNode(0);
        ListNode* after = after_head;

        // Ab hum original list ke har node pe loop chalaenge
        while (head != nullptr) {
            // Agar node ka value x se chhota hai, toh use before list mein
            // daalenge
            if (head->val < x) {
                before->next = head;
                before = before->next;
            } else {
                // Nahi toh use after list mein daalenge
                after->next = head;
                after = after->next;
            }
            // Next node pe jaane ke liye head ko update karenge
            head = head->next;
        }

        // after list ke end mein null daalenge
        after->next = nullptr;
        // before list ke end mein after list jod denge
        before->next = after_head->next;

        // Finally, before list ka head return karenge
        return before_head->next;
    }
};
