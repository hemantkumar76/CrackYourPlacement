#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;
};

// Yeh function linked list ko zigzag fashion mein arrange karta hai
void zigZagList(Node* head)
{
    // Agar flag true hai, toh next node chahiye bada
    bool flag = true;

    // Linked list traverse karenge starting from head.
    Node* current = head;
    while (current->next != NULL) {
        if (flag) 
        {
            // Agar A > B > C jaisa situation hai
            // Jahan A, B aur C consecutive Nodes hain list mein
            // Toh hum A > B < C kar denge B aur C ko swap karke
            if (current->data > current->next->data)
                swap(current->data, current->next->data);
        }
        else 
        {
            // Agar A < B < C jaisa situation hai
            // Jahan A, B aur C consecutive Nodes hain list mein
            // Toh hum A < C > B kar denge B aur C ko swap karke
            if (current->data < current->next->data)
                swap(current->data, current->next->data);
        }

        current = current->next;
        flag = !flag; /* flag ko flip karenge reverse checking ke liye */
    }
}

void push(Node** head_ref, int new_data)
{
    
    struct Node* new_Node = new Node;

    
    new_Node->data = new_data;

    
    new_Node->next = (*head_ref);

    
    (*head_ref) = new_Node;
}

void printList(struct Node* Node)
{
    while (Node != NULL) {
        printf("%d->", Node->data);
        Node = Node->next;
    }
    printf("NULL");
}

int main(void)
{
    struct Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);

    printf("Given linked list \n");
    printList(head);

    zigZagList(head);

    printf("\nZig Zag Linked list \n");
    printList(head);

    return (0);
}
