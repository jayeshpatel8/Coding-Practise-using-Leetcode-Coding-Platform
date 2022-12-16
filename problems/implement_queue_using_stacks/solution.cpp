class MyQueue {
public:
    stack<int> p1,p2;
    MyQueue() {
        
    }
    
    void push(int x) {
        p2.push(x);
    }
    
    int pop() {
        if (p1.empty()){
            while (!p2.empty())
                {
                    p1.push(p2.top());
                    p2.pop();
                }
        }
        if (!p1.empty()){
        auto ans = p1.top(); p1.pop();
        return ans;
        }
        return 0;
    }
    
    int peek() {
        if (p1.empty()){
            while (!p2.empty())
                {
                    p1.push(p2.top());
                    p2.pop();
                }
        }
        if (!p1.empty()){
        auto ans = p1.top(); 
        return ans;
        }
        return 0;
    }
    
    bool empty() {
        return p1.empty() && p2.empty();
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