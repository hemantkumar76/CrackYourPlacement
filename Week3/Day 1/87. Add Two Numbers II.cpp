class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // do stacks banate hain jisme hum linked list ke elements dalenge
        stack<int> s1, s2;
        
        // l1 ke elements ko s1 mein dalte hain
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        // l2 ke elements ko s2 mein dalte hain
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int sum = 0;
        ListNode *res = new ListNode(0);
        while(!s1.empty() || !s2.empty()){
            // agar s1 mein elements hain to usko sum mein add karte hain
            if(!s1.empty()){sum += s1.top(); s1.pop();}
            // agar s2 mein elements hain to usko sum mein add karte hain
            if(!s2.empty()){sum += s2.top(); s2.pop();}
            // res ke value ko sum ka last digit se update karte hain
            res->val = sum % 10;
            // ek naya node banate hain jiska value sum ka first digit hoga
            ListNode *head = new ListNode(sum / 10);
            // is naye node ke next ko res se link karte hain
            head->next = res;
            // res ko head se update karte hain
            res = head;
            // sum ko 10 se divide karte hain
            sum /= 10;
        }
        
        // agar list ke start mein 0 hai to usko skip karte hain
        return res->val == 0 ? res->next : res;
    }
};
