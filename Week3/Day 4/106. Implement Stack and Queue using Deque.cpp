// C++ Program to implement stack and queue using Deque
#include <bits/stdc++.h>
using namespace std;

// Structure for a node of deque
struct DQueNode {
    int value;
    DQueNode* next;
    DQueNode* prev;
};

// Implementation of deque class
class Deque {
private:

    // Pointers to head and tail of deque
    DQueNode* head;
    DQueNode* tail;

public:
    // Constructor
    Deque() {
        head = tail = NULL;
    }

    // Agar list empty hai toh
    bool isEmpty() {
        if (head == NULL)
            return true;
        return false;
    }

    // List mein kitne nodes hain usko count karte hain
    int size() {
        // Agar list empty nahi hai toh
        if (!isEmpty()) {
            DQueNode* temp = head;
            int len = 0;
            while (temp != NULL) {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }

    // Pehli position par insert karte hain
    void insert_first(int element) {
        // DQueNode type ka node allocate karte hain
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // Agar element pehla element hai
        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    // Aakhri position par insert karte hain
    void insert_last(int element) {
        // DQueNode type ka node allocate karte hain
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // Agar element pehla element hai
        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    // Pehli position se element remove karte hain
    void remove_first() {
        // Agar list empty nahi hai toh
        if (!isEmpty()) {
            DQueNode* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            delete temp;
            if(head == NULL) tail = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    // Aakhri position se element remove karte hain
    void remove_last() {
        // Agar list empty nahi hai toh
        if (!isEmpty()) {
            DQueNode* temp = tail;
            tail = tail->prev;
            if(tail) tail->next = NULL;
            delete temp;
            if(tail == NULL) head = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    // Deque mein elements ko display karte hain
    void display() {
        // Agar list empty nahi hai toh
        if (!isEmpty()) {
            DQueNode* temp = head;
            while (temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;
    }
};

// Stack class ka implementation using Deque
class Stack : public Deque {
public:
    // Element ko stack ke top par push karte hain
    // Deque ke insert_last function ka use karte hain
    void push(int element) {
        insert_last(element);
    }

    // Stack ke top se element ko remove karte hain
    // Deque ke remove_last function ka use karte hain
    void pop() {
        remove_last();
    }
};

// Queue class ka implementation using Deque
class Queue : public Deque {
public:
    // Element ko queue ke aakhri mein insert karte hain
    // Deque ke insert_last function ka use karte hain
    void enqueue(int element) {
        insert_last(element);
    }

    // Queue ke pehle se element ko remove karte hain
    // Deque ke remove_first function ka use karte hain
    void dequeue() {
        remove_first();
    }
};

// Driver Code
int main() {
    // Stack ka object banate hain
    Stack stk;

    // Stack ke top par 7 aur 8 ko push karte hain
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();

    // Ek element ko pop karte hain
    stk.pop();
    cout << "Stack: ";
    stk.display();

    // Queue ka object banate hain
    Queue que;

    // Queue mein 12 aur 13 ko insert karte hain
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();

    // Queue se ek element ko delete karte hain
    que.dequeue();
    cout << "Queue: ";
    que.display();

    cout << "Stack ka size hai: " << stk.size() << endl;
    cout << "Queue ka size hai: " << que.size() << endl;
    return 0;
}
