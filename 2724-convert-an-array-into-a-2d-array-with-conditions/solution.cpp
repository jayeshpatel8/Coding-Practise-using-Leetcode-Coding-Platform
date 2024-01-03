class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> cnt(nums.size()), idx(cnt);
        
        for (auto i : nums) cnt[i-1]++;
        iota(begin(idx),end(idx),0);
        sort(begin(idx),end(idx),[&](int a, int b){
            return  cnt[a] > cnt[b]   ;
        }
        );
        
        
        vector<vector<int>> ans(cnt[idx[0]]);
        for (int i=0; i<nums.size() && cnt[idx[i]] > 0; i++){
            for (int j=0,n=idx[i]; j<cnt[n]; j++)
               ans[j].push_back(n+1);
        }
        return ans;
    }
};
