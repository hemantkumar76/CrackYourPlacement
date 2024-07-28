class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // Ek stack banate hain
        stack<int> stack;
        ListNode* curr = head;
        
        // Linked list ke saare elements ko stack mein push kar dete hain
        while (curr) {
            stack.push(curr->val);
            curr = curr->next;
        }
        
        curr = head;
        
        // Linked list ke elements ko stack ke top element se compare karte hain
        // Agar dono same hain, toh stack se pop kar dete hain aur linked list mein aage badhte hain
        while (curr && curr->val == stack.top()) {
            stack.pop();
            curr = curr->next;
        }
        
        // Agar saari elements check karne ke baad linked list khatam ho gayi hai, 
        // toh linked list palindrome hai, toh true return karte hain
        // Agar linked list khatam nahi hui hai, toh linked list palindrome nahi hai, toh false return karte hain
        return curr == nullptr;
    }
};
