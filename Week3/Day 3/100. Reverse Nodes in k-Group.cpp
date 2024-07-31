class Solution {
public:
    // Function to reverse k nodes in a linked list
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case: agar head null hai ya k 1 hai, toh original list return karenge
        if (!head || k == 1) return head;

        // Dummy node banayenge
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        // prev aur curr pointers initialize karenge
        ListNode* curr = dummy, *prev = dummy;
        int count = 0;

        // Pehle, list mein kitne nodes hain, wo count karenge
        while (curr->next) {
            curr = curr->next;
            count++;
        }

        // Phir, har k nodes ko reverse karenge
        while (count >= k) {
            curr = prev->next;
            ListNode* next = curr->next;
            // k nodes ko reverse karenge
            for (int i = 1; i < k; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            // prev aur count ko update karenge
            prev = curr;
            count -= k;
        }

        // Modified list return karenge
        return dummy->next;
    }
};
