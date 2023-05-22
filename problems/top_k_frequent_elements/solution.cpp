class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k==nums.size())return nums;
        int mi = *min_element(begin(nums),end(nums));
        int ma = *max_element(begin(nums),end(nums));   
        mi = (mi < 0? mi : 0);
        vector<int> freq(ma-mi+1),ids(freq),ret;
        for (auto i : nums) freq[i-mi]++;
        iota(begin(ids),end(ids),0);
        partial_sort(begin(ids),begin(ids)+k,end(ids),[&](auto a, auto b){ return freq[a] > freq[b];});
        for (int i=0; i<k; i++)
            ret.push_back(ids[i]+mi);
        return ret;
    }
};