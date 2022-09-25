class MyCircularQueue {
public:
    vector<int> q;
    int r=0,w=-1,sz= 0, size=0;
    MyCircularQueue(int k) {
        size = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if (sz>=size) return false;        
        sz++;
        w = (w+1)%size;
        q[w]= value;
        
        return true;
    }
    
    bool deQueue() {
        if (sz<=0) return false;
        r =  (r + 1) % size;
        sz--;
        return true;
    }
    
    int Front() {
        if (sz <= 0) return -1;
        int ans = q[r];
        return ans;
    }
    
    int Rear() {
        if (sz <=0 ) return -1;

        return q[w];        
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */