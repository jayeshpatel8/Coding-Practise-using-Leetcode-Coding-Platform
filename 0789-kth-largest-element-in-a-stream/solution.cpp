class KthLargest {
public:
    multiset<int> mst;
    int sz=0,K;
    KthLargest(int k, vector<int>& nums) {
        for (auto i : nums) mst.insert(i),sz++;
        int n = nums.size()-k;
        while (n-- > 0 )
        
            mst.erase(begin(mst)),sz--;
        K=k;
    }
    
    int add(int val) {
        mst.insert(val);
        if (++sz > K)
            mst.erase(begin(mst)),--sz;        
        return *begin(mst);
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
