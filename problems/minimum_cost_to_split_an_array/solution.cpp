class Solution {
public:
int dp[1001]={}, K ;
    int minCost(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        K=k;
        return dfs(nums,0);
    }
    
    int dfs(vector<int>& nums, int i){
        if (i>= nums.size()) return 0;
        if (dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        vector<int> cnt(nums.size());
        for (int j=i, trim  = 0; j<nums.size(); j++){
            if (cnt[nums[j]]++)
                trim += cnt[nums[j]] ==2 ? 2 : 1;
            ans = min(ans, K + trim + dfs(nums,j+1));
        }
        return dp[i]=ans;
    }   
};