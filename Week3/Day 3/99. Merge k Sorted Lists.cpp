class Solution {
public:
    // Function to merge k sorted linked lists
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min heap banayenge
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        // Sabhi linked lists ke pehle node ko min heap mein daalenge
        for (auto head : lists) {
            if (head) {
                pq.push({head->val, head});
            }
        }

        // Dummy node banayenge
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        // Jab tak min heap khali nahi hota, heap se smallest element ko nikaal kar result list mein jodenge
        while (!pq.empty()) {
            pair<int, ListNode*> top = pq.top();
            pq.pop();

            curr->next = top.second;
            curr = curr->next;

            // Agar current list mein aur nodes hain toh unhe heap mein daalenge
            if (top.second->next) {
                pq.push({top.second->next->val, top.second->next});
            }
        }

        // Result list return karenge
        return dummy->next;
    }
};
