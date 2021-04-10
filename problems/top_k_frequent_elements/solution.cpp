class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq1;
        
        for(auto i : nums) freq1[i]++;
        multimap<int,int> freq;
        for (auto & [k,v] : freq1) freq.insert({v,k});
        int fsz = freq.size();
        while(fsz-- > k) freq.erase(freq.begin());
        vector<int> ans;
        for (auto & [k,v]  : freq) ans.push_back(v);
        return ans;
    }
};