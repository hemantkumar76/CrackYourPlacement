class Solution {
public:
    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Jab tak dono lists mein nodes hain
        while (l1 && l2) {
            // Chhote node ko select karenge aur usko result list mein daalenge
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Agar koi ek list bach gayi hai, toh usko result list ke end mein jod
        // denge
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        // Agar list khali hai ya sirf ek node hai, toh wahi list return karenge
        if (!head || !head->next)
            return head;

        // List ko do parts mein divide karenge
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;

        // Dono parts ko sort karenge
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Sorted parts ko merge karenge
        return merge(left, right);
    }
};
