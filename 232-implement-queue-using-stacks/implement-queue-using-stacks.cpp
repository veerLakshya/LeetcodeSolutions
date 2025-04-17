class MyQueue {
public:
    stack<int> f,s;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(f.size()){
            s.push(f.top());
            f.pop();
        }
        f.push(x);
        while(s.size()){
            f.push(s.top());
            s.pop();
        }
    }
    
    int pop() {
        int temp = f.top();
        f.pop();
        return temp;
    }
    
    int peek() {
        return f.top();
    }
    
    bool empty() {
        return !f.size();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */