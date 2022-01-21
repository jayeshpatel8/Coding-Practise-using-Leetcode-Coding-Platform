class CustomStack {
public:
    vector<int> st;
    //priority_queue<array<int,2>> pq;
    int cur=0, N ;//, sum = 0;
    CustomStack(int maxSize) {
        N  = maxSize;
        st.resize(maxSize);
    }
    
    void push(int x) {
        if (cur == N) return;
        st[cur++] = x;
    }
    
    int pop() {
     if (cur == 0) return -1;
       
        return st[--cur];   
    }
    
    void increment(int k, int val) {
        for ( int i=0, m = min(k,cur); i<m; i++)
            st[i] +=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */