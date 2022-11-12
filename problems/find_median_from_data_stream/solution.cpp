class MedianFinder {
public:
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>, greater<int>> minpq;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minpq.push(num);
        maxpq.push(minpq.top());
        minpq.pop();
        if (minpq.size() < maxpq.size()) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        
    }
    
    double findMedian() {
        if (minpq.size() == maxpq.size()) {    
            return (minpq.top() + maxpq.top()) / 2.0;        
        }
        else return minpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */