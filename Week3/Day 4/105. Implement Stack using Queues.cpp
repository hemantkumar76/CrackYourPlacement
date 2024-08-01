#include <queue>

class MyStack {
public:
    std::queue<int> q1, q2; // Do queues banate hain
    void push(int x) {
        // Sabse pehle, nayi value ko q1 mein push karte hain
        q1.push(x);

        // Phir, q2 mein q1 ke saare elements ko move kar dete hain
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }

        // Ab, q1 aur q2 ko swap kar dete hain
        std::swap(q1, q2);
    }

    int pop() {
        // Stack ke top element ko remove karne ke liye, q2 se pop karte hain
        int top = q2.front();
        q2.pop();
        return top; // Pop kiye hue element ko return karte hain
    }

    int top() {
        // Stack ke top element ko return karne ke liye, q2 ka front return
        // karte hain
        return q2.front();
    }

    bool empty() {
        // Stack khali hai ya nahi check karne ke liye, q2 ki emptiness check
        // karte hain
        return q2.empty();
    }
};
