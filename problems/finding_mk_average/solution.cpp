class MKAverage {
    int M,K,sz,pos;
    vector<int> v;
    multiset<int> mid,left,right;
    long  sum;
public:
    MKAverage(int m, int k) : sz(m - 2 * k){
        M=m; K=k; sum=0;v = vector<int>(m);pos = 0;
    }
    void remove(int n){
    if (n <= *rbegin(left))
        left.erase(left.find(n));
    else if (n <= *rbegin(mid)) {
       auto it = mid.find(n); 
       sum -= *it;
       mid.erase(it);
    }
    else
        right.erase(right.find(n));
    if (left.size() < K) {
        left.insert(*begin(mid));
        sum -= *begin(mid);
        mid.erase(begin(mid));
    }
    if (mid.size() < sz) {
        mid.insert(*begin(right));
        sum += *begin(right);
        right.erase(begin(right));
    }
}
    void add(int n){
            left.insert(n);
    if (left.size() > K) {
        auto it = prev(end(left));
        mid.insert(*it);
        sum += *it;
        left.erase(it);
    }
    if (mid.size() > sz) {
        auto it = prev(end(mid));
        sum -= *it;
        right.insert(*it);
        mid.erase(it);
        }                
    }
    void addElement(int num) {
    if (pos >= M)
        remove(v[pos % M]);
    add(num);
    v[pos++ % M] = num;
    }
    
    int calculateMKAverage() {
        if (pos>=M) return sum/sz;
        return -1;
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */