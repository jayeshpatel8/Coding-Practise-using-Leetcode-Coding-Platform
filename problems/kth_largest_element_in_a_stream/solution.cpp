class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int K ,sz = 0;
    KthLargest(int k, vector<int>& nums) {
        K= k;
        for(auto i : nums) 
            pq.push(i);
        sz=nums.size();
        while (sz > k  )
            pq.pop(),sz--;
    }
    
    int add(int val) {
        if (sz < K)
            pq.push(val),sz++;
        else if (val > pq.top())
            pq.pop(),pq.push(val);
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */