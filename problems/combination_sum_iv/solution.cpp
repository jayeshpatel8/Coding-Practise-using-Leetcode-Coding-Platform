class Solution {
public:
    int dp[1001];
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        sort(begin(nums),end(nums));
        return dfs(nums,target);
    }
    int dfs(vector<int>& nums, int target) {
        if (target == 0) return 1;
        
        if (dp[target] >= 0) return dp[target];
        int ans = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i] <= target){
                ans += dfs(nums,target-nums[i]);
            }
            else
                break;
        }
        return dp[target] = ans;
    }
};