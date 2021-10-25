class MinStack {
public:
    int minv = INT_MAX;
    vector<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if (val <= minv) 
          st.push_back(minv),minv = val;
        st.push_back(val);
    }
    
    void pop() {
        if (st.back() == minv)
          st.pop_back(), minv = st.back();
        st.pop_back();
        
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minv;
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