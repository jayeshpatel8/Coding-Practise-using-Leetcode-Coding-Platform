class Solution {
public:
int dp[21][21], N ;
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        N = nums.size();
        if (N<=2) return true;
        return dfs(nums,0,N-1)>=0;
    }
    int dfs(vector<int> &nums, int i,int j){
        if (i>j)return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int ans= max(nums[i] - dfs(nums,i+1,j),
            nums[j] - dfs(nums,i,j-1));
        
        return dp[i][j] = ans;
    }
};