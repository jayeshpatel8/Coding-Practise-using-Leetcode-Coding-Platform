class Solution {
public:
int dp[52][52][102], mod=1e9 + 7;
    int numOfArrays(int n, int m, int k) {
        
        memset(dp,-1,sizeof(dp));

        return dfs(n,m,k);
    }
    int dfs (int n, int m, int k, int maxv=-1){
        if (k>m ) return 0;
        if (n == 0) return k==0; 
        if (k<0) return 0;
        if (dp[n][k][maxv+1] != -1) return  dp[n][k][maxv+1];
        int ans = 0 ,i = 1;
        for ( ; i<=maxv; i++)
            ans = (ans + dfs(n-1,m,k,maxv)) % mod;
        for ( ; i<=m; i++)
            ans = (ans + dfs(n-1,m,k-1,i)) % mod;
        
        return  dp[n][k][maxv+1] = ans;
    }
};