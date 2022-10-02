class Solution {
    int dp[31][1001] = {}, mod = 1e9 + 7;
public:
    int numRollsToTarget(int n, int k, int target) {
        dp[0][0]=1;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=k; j++){
                for (int t=j; t<=target; t++)
                    dp[i][t] = (dp[i][t] + dp[i-1][t - j]) %mod;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget2(int n, int k, int target) {    
        memset(dp,-1,sizeof(dp));
        return dfs(n,k,target);
    }
    int dfs(int n, int k, int target) {
        if (n == 0 )
            return target == 0;
        if (target <= 0) return 0;
        if (dp[n][target] != -1 ) return dp[n][target];
        long ans = 0;
        for (int i=1; i<=k; i++){
            ans = (ans + dfs(n-1,k,target- i)) % mod;
        }
        return dp[n][target] = ans;
    }    
};