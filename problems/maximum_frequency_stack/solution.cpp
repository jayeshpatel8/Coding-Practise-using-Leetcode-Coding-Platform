class FreqStack {
public:
    unordered_map<int,int>f;
    unordered_map<int,stack<int>>st;
    int mfreq;
    FreqStack() {
        mfreq=-1;
    }
    
    void push(int val) {
        int fr = ++f[val];
        if (fr > mfreq) mfreq= fr;
        st[fr].push(val);

    }
    
    int pop() {
        int ans =  st[mfreq].top();
        st[mfreq].pop();
        if (st[mfreq].empty())
            mfreq--;           
        --f[ans];
        return ans;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */