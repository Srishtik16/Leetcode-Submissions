class MinStack {
public:
    stack<pair<int, int>> st; // {min val, curr val}
    MinStack() {
        ;
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        }
        else {
            st.push({min(st.top().first, val), val});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().second;
    }
    
    int getMin() {
        return st.top().first;
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