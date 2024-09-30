class CustomStack {
public:
    vector<int> st, lazy;
    int top;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        lazy.resize(maxSize);
        top = -1;
    }
    
    void push(int x) {
        if(top + 1 < st.size()) {
            st[++top] = x;
        }
    }
    
    int pop() {
        if(top < 0) {
            return -1;
        }
        int res = st[top] + lazy[top];
        if(top > 0) {
            lazy[top - 1] += lazy[top];
        }
        lazy[top] = 0;
        top--;
        return res;
    }
    
    void increment(int k, int val) {
        if(top < 0) {
            return;
        }
        int index = min(k - 1, top);
        lazy[index] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */