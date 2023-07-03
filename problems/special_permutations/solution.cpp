class Solution {
public:
int dp[14][1<<14] ,mod = 1e9 +7;
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,0,0);
    }
    int dfs(vector<int> & nums, int i, int mask){
        if (mask == (1<<nums.size())-1) return 1;
        if (dp[i][mask] != -1) return dp[i][mask];
        int ans = 0;
        for (int j=0; j<nums.size(); j++){
            if ((mask & (1<<j))==0 && ( mask==0 || nums[i] % nums[j] ==0 || nums[j] % nums[i] ==0 )){
                ans = (ans + dfs(nums, j, mask | (1<<j)))%mod;
            }
            
        }
        return dp[i][mask] =ans;
    }
};