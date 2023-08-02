class Solution {
public:
    vector<vector<int>> ans;
    int N;
    vector<vector<int>> permute(vector<int>& nums) {
        N= nums.size();
        dfs(nums);    
        return ans;
    }
    void dfs(vector<int> & nums, int i=0){
        if (i==N){
            ans.push_back(nums);
            return;
        }
        for (int j=i; j<N; j++){
            swap(nums[i],nums[j]);
            dfs(nums, i+1);
            swap(nums[i],nums[j]);
        }
    }
};