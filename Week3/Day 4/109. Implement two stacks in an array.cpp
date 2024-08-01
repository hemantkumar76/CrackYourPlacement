#include <bits/stdc++.h>

using namespace std;

class twoStacks {
    int *arr;
    int size;
    int top1, top2;

public:
    twoStacks(int n=100) { 
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size; 
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        // Agar space available hai toh element ko stack1 me push karte hain
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        }
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // Agar space available hai toh element ko stack2 me push karte hain
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        // Agar stack1 khali nahi hai toh uska top element pop karte hain
        if (top1 >= 0) {
            int x = arr[top1];
            top1--;
            return x;
        }
        else {
            return -1;
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        // Agar stack2 khali nahi hai toh uska top element pop karte hain
        if (top2 < size) {
            int x = arr[top2];
            top2++;
            return x;
        }
        else {
            return -1;
        }
    }
};
