class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Agar list khali hai ya sirf ek node hai, toh wahi list return karenge
        if (head == nullptr || head->next == nullptr)
            return head;

        // Ek dummy node banayenge jo sorted list ke shuru mein hoga
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // Two pointers rakhenge - prev aur current
        ListNode* prev = dummy;
        ListNode* current = head;

        // Jab tak list khatam nahi hoti, tab tak loop chalayenge
        while (current != nullptr) {
            // Jab tak next node hai aur current node ka value next node ke
            // value ke barabar hai tab tak current node ko aage badhate rahenge
            while (current->next != nullptr &&
                   current->val == current->next->val) {
                current = current->next;
            }

            // Agar prev ka next current hai, toh prev ko aage badhate
            // hain Kyunki iska matlab hai ki current duplicate nahi tha
            if (prev->next == current) {
                prev = prev->next;
            } else {
                // Nahi toh prev ka next current ke next ko point karega
                // Kyunki current duplicate tha
                prev->next = current->next;
            }

            // current ko uske next pe move karte hain
            current = current->next;
        }

        // Finally, dummy node ke next ko return karenge
        // Kyunki dummy node ke next pe humari modified list hai
        return dummy->next;
    }
};
