class Solution {
public:
    int dp[501][501];
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,0,nums.size()-1);
    }
    int dfs(vector<int>& nums, int i, int j){
        if (i>j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        // k is last blast (not latest)
        // [i,j] is outside i an j is already bursted now burst among [i,j]
        // [i....k...j] => (i-1) * k (j+1) + prev burst from  remaining dfs(i,k-1) + dfs(k+1,j)
        for ( int  k = i; k<=j; k++){
            ans = max(ans , (i == 0? 1 : nums[i-1]) * nums[k] * (j+1>=nums.size() ? 1 : nums[j+1]) + 
                       dfs (nums, i,k-1)
                     + dfs (nums, k+1,j));
        }
        return dp[i][j] = ans;
    }
};