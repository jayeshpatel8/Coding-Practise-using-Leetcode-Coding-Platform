class Solution {
    public: vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    { 
        vector<int> idx(nums.size()); 
        iota(begin(idx), end(idx),0); sort(begin(idx),end(idx),[&](auto i, auto j){return nums[i] < nums[j];});
        
        vector<vector<int>> g{{idx[0]}}; 
        for (auto i=1; i<nums.size(); i++){
             if (nums[idx[i]] - nums[idx[i-1]] <= limit)
                 g.back().push_back(idx[i]); 
            else 
                g.push_back({idx[i]}); 
        } 

        for (auto &grp : g){
            vector<int> e;
            for (auto i : grp) e.push_back(nums[i]);
            sort(begin(grp), end(grp));
            int j=0;
            for (auto i : grp) nums[i] = e[j++];
        }
        return nums; 
    }
};

