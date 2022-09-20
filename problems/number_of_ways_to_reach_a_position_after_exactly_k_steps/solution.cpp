class Solution {
public:
    int dp[3001][1001], mod = 1e9 + 7;
    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(startPos+1000,endPos+1000,k);
    }
    int dfs(int st, int en, int k){
        long ans=0;
        if (st==en){
            if (k==0)
                return 1;
        }
        if (k<0) return 0;
        if (dp[st][k] != -1) return dp[st][k];
        ans = (ans + dfs(st-1,en,k-1))%mod;
        ans = (ans + dfs(st + 1,en,k-1))%mod;
        return dp[st][k] = ans;
    }
};