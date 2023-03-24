class Solution {
public:
    int dp[100001][17];
    int minOperations(int n) {
        return __builtin_popcount(n ^ (n * 3));
        memset(dp,-1,sizeof(dp));
        return dfs(n,0);
    }
    int dfs(int n, int i){
        if (n==0) return 0;
        if (n>1e5|| i>=17) return __builtin_popcount(n);
        if (dp[n][i]!= -1) return dp[n][i];

        int bit= (1<<i), ans = dfs(n,i+1) ;
        if (n & bit){
            ans= min({ans,1 + dfs(n-bit,i+1),1 + dfs(n+bit,i+1)});
        }
        return dp[n][i] = ans;

    }
};