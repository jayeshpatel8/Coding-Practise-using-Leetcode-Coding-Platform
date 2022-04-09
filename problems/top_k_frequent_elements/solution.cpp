class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for (auto i  : nums)freq[i]++;
        vector<vector<int>> bucket(nums.size()+1);
        for (auto [k,v] : freq)
            bucket[v].push_back(k);
        vector<int> ans;
        for (int i=nums.size(); i>=0; i--){
            if (bucket[i].empty()) continue;
            for (auto j : bucket[i]){
                if (k--==0) return ans;
                ans.push_back(j);
            }
        }
        return ans;
    }
};