class FindSumPairs {
public:
    unordered_map<int,int> freq;
    vector<int> n1, n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2= nums2;
        for (auto i : nums2)
            freq[i]++;
    }
    
    void add(int i, int val) {
        if (freq[n2[i]]-- == 1)
            freq.erase(n2[i]);
        
        n2[i]+=val;
        freq[n2[i]]++;
    }
    
    int count(int tot) {
        int ans =0;
        for (auto i : n1){
            auto diff = tot - i;
            if (freq.count(diff)){
                ans += freq[diff];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
