class MinStack {
public:
    vector<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.size() == 0) st.push_back({val,val});
        else{
            int last = st.back().second;
            st.push_back({val,min(val, last)});
        }
    }
    
    void pop() {
        if(st.size()) st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */