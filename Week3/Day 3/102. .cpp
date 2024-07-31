class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);    
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int value_hai = st2.top();
        st2.pop();
        return value_hai;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int value_hai = st2.top();
        return value_hai;
    }
    
    bool empty() {
        return st1.empty() and st2.empty();
    }
};
// worst day 💔💔
