class MyStack {
public:
    queue<int> q1;
    int ctop;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        ctop=x;
    }
    
    int pop() {
        auto v = 0;
        if (!q1.empty()){
            int n = q1.size();
            while (n-- > 1)
                q1.push( ctop=q1.front()), q1.pop();
            v = q1.front(); q1.pop();            
        }
        return v;
    }
    
    int top() {
        auto v = 0;
        if (!q1.empty()){
            v=ctop;           
        }
        return v;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */