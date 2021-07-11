class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> s;
    multiset<int>::iterator it = s.begin();
    bool odd = false;
    MedianFinder() {
    }
    
    void addNum(int num) {
        s.insert(num);
        
        if (it==s.end()|| (!odd && num>=*it)) it++;
        else if (odd && num<*it) it--;
        odd = !odd;
    }
    
    double findMedian() {
        if (odd)return *it;
         
        return (*it + *next(it))/ 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */