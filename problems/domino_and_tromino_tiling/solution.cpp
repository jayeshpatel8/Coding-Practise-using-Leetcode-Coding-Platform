class Solution {
public:
    int dp[1001][2], mod = 1e9 + 7;
    int numTilings(int n) {
        if(n<=2) return n;
        memset(dp,-1,sizeof(dp));
        return dfs(n,1);
    }
    long dfs(int n, bool done){
        if (n<0) return 0;
        if (n==0) return done;

        
        if (dp[n][done]!= -1) return dp[n][done];
        
        long ans = 0;
        if (done)
            ans += dfs(n-1, 1) + dfs(n-2,1) + 2 * dfs(n-2,0);
        else{
            ans +=  dfs(n-1,0) + dfs(n-1,1);
        }
        return dp[n][done] = ans % mod;
    }
};
/*

// dom
n>= 1  vertical 
n>=2  2 Horiz

// trom
n>=3 2 trom
n>=5 2 trom + 2  dom

*/