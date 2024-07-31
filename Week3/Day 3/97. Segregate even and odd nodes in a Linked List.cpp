//Note Copied and pasted from GFG Directly 
#include <bits/stdc++.h> 
using namespace std; 

/* Ek node singly linked list ka */
class Node 
{ 
public: 
    int data; 
    Node *next; 
    Node (int d) {
        data = d;
        next = nullptr;
    }
}; 

void segregateEvenOdd(Node **head_ref) 
{ 
    Node *end = *head_ref; 
    Node *prev = nullptr; 
    Node *curr = *head_ref; 

    /* Last node tak pointer le jayenge */
    while (end->next != nullptr) 
        end = end->next; 

    Node *new_end = end; 

    /* Pehle even node se pehle ke saare odd nodes ko end ke baad move karenge */
    while (curr->data % 2 != 0 && curr != end) 
    { 
        new_end->next = curr; 
        curr = curr->next; 
        new_end->next->next = nullptr; 
        new_end = new_end->next; 
    } 

    /* Agar koi even node hai toh ye steps follow karenge */
    if (curr->data%2 == 0) 
    { 
        /* Head pointer ko pehle even node pe point karenge */
        *head_ref = curr; 

        /* Ab current pehle even node ko point karega */
        while (curr != end) 
        { 
            if ( (curr->data) % 2 == 0 ) 
            { 
                prev = curr; 
                curr = curr->next; 
            } 
            else
            { 
                /* prev aur current ke beech ka link tod denge */
                prev->next = curr->next; 

                /* curr ka next NULL kar denge */
                curr->next = nullptr; 

                /* curr ko end pe move karenge */
                new_end->next = curr; 

                /* curr ko new end of list banayenge */
                new_end = curr; 

                /* moved node ke next pe current pointer update karenge */
                curr = prev->next; 
            } 
        } 
    } 

    /* Ye lines execute karne se pehle prev set hona chahiye */
    else prev = curr; 

    /* Agar 1 se jyada odd nodes hain aur original list ka end odd hai toh 
    is node ko end pe move karenge taaki modified list mein odd numbers ka order maintain rahe */
    if (new_end != end && (end->data) % 2 != 0) 
    { 
        prev->next = end->next; 
        end->next = nullptr; 
        new_end->next = end; 
    } 
    return; 
} 


/* Function to print nodes in a given linked list */
void printList(Node *node) 
{ 
    while (node != nullptr) 
    { 
        cout << node->data <<" "; 
        node = node->next; 
    } 
} 

/* Driver code*/
int main() 
{ 
    /* Sample linked list banayenge jaise ki 
    0->2->4->6->8->10->11 */
    Node* head = new Node(0);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = 
                                   new Node(10);
    head->next->next->next->next->next->next = 
                                   new Node(11);

    cout << "Original Linked list "; 
    printList(head); 

    segregateEvenOdd(&head); 

    cout << "\nModified Linked list "; 
    printList(head); 

    return 0; 
} 
