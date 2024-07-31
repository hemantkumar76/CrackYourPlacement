#include <bits/stdc++.h>
using namespace std;

// Linkedlist Node ka structure
struct Node {
    int data;
    struct Node* next;
};

// Function ek naya Node banane ke liye linkedlist mein
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Function linked list ko reverse karne ke liye
void reverselist(Node** head)
{
    // prev aur current pointers ko initialize karenge
    Node *prev = NULL, *curr = *head, *next;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

// Function linked list print karne ke liye
void printlist(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        if (head->next)
            cout << "-> ";
        head = head->next;
    }
    cout << endl;
}

// Function linked list ko rearrange karne ke liye
void rearrange(Node** head)
{
    // 1) Tortoise aur hare method se middle point dhundenge
    Node *slow = *head, *fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 2) Linked list ko do halves mein split karenge
    // head1, pehle half ka head 1 -> 2
    // head2, doosre half ka head 3 -> 4
    Node* head1 = *head;
    Node* head2 = slow->next;
    slow->next = NULL;
    // 3) Doosre half ko reverse karenge, i.e., 4 -> 3
    reverselist(&head2);
    // 4) Alternate nodes ko merge karenge
    *head = newNode(0); // Dummy Node assign karenge
    // curr is the pointer to this dummy Node, jo naye list ke liye use hoga
    Node* curr = *head;
    while (head1 || head2) {
        // Pehle list se element add karenge
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        // Phir doosre list se element add karenge
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    // Naye list ka head ko head pointer assign karenge
    *head = (*head)->next;
}

// Driver program
int main()
{
    Node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printlist(head); // Original list print karenge
    rearrange(&head); // List modify karenge
    printlist(head); // Modified list print karenge
    return 0;
}
