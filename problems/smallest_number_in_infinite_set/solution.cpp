class SmallestInfiniteSet {
public:
    set<int> st;
    int n=1;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (st.empty()) return n++;
        int ans = *st.begin();
        st.erase(st.begin());
        return ans;
    }
    
    void addBack(int num) {
        if (num<n) st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */