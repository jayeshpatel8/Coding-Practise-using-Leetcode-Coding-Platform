class Solution {
public:
    vector<vector<int>> ans;
    int N;
    vector<vector<int>> subsets(vector<int>& nums) {
        
        N = nums.size();
        vector<int> v;
        dfs(nums, 0,v);
        return ans;
    }
    void dfs(vector<int>& nums, int i,vector<int>&v){
        ans.push_back(v);
        if (i >= N) return;
        v.push_back(0);
        for (int j = i; j<N; j++){
            v.back()=nums[j];
            dfs(nums,j+1,v);
        }
        v.pop_back();
    }
};