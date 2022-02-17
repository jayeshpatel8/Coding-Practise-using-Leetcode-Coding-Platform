class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0,vector<int>()={});
        return ans;
    }
    void dfs(vector<int>& cand, int target, int i, vector<int>& cur){
        if (target == 0) { 
            ans.push_back(cur); return;
        }
        if (i>=cand.size() || target<0) return ;
        
        cur.push_back(cand[i]);
        dfs(cand,target-cand[i],i,cur);
        cur.pop_back();        
        dfs(cand,target,i+1,cur);
    }
};