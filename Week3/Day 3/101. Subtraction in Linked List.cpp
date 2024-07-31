class Solution {
public:
    // Function to subtract two linked lists
    Node* subLinkedList(Node* head1, Node* head2) {
        // Dono linked lists ko reverse karenge
        head1 = reverse(head1);
        head2 = reverse(head2);

        // Check karenge ki kaunsi linked list badi hai
        bool isSwap = false;
        if (isSmaller(head1, head2)) {
            swap(head1, head2);
            isSwap = true;
        }

        // Result linked list ke liye dummy node banayenge
        Node* dummy = new Node(0);
        Node* curr = dummy;

        // Carry initialize karenge
        int carry = 0;

        // Dono linked lists ke nodes ko subtract karenge
        while (head1 || head2) {
            // Dono linked lists ke current nodes ke values ko fetch karenge
            int a = (head1) ? head1->data : 0;
            int b = (head2) ? head2->data : 0;

            // Subtract karenge
            int sub = ((a + 10) - (b + carry)) % 10;

            // Carry update karenge
            carry = ((a + 10) - (b + carry)) < 10 ? 1 : 0;

            // Result linked list mein new node banayenge
            curr->next = new Node(sub);
            curr = curr->next;

            // Dono linked lists ke pointers ko aage badhayenge
            if (head1) head1 = head1->next;
            if (head2) head2 = head2->next;
        }

        // Agar carry bach gayi hai toh use result linked list mein add karenge
        if (carry) curr->next = new Node(carry);

        // Result linked list ko reverse karenge
        Node* res = reverse(dummy->next);

        // Agar swap hua tha toh result linked list ke saare nodes ko 9 se subtract karenge
        if (isSwap) res = subtractFromNine(res);

        // Result linked list return karenge
        return res;
    }

    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL, *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to check if first linked list is smaller than the second
    bool isSmaller(Node* head1, Node* head2) {
        while (head1 && head2 && head1->data == head2->data) {
            head1 = head1->next;
            head2 = head2->next;
        }
        if (!head2 && head1) return false;
        if (!head1 && head2) return true;
        return (head1->data < head2->data);
    }

    // Function to subtract all nodes from 9
    Node* subtractFromNine(Node* head) {
        Node* curr = head;
        while (curr) {
            curr->data = 9 - curr->data;
            curr = curr->next;
        }
        return head;
    }
};
