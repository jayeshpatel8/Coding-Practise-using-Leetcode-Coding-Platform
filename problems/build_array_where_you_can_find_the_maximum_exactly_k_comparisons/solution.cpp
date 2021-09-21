class Solution {
public:
    //       N,M,K
    int dp[52][102][52] ={}, mod=1e9 + 7;
    
    int numOfArrays(int N, int M, int K) {
        
        for (int i=1; i<=M; i++) dp[1][i][1]=1; //basecase
        
        for (int i=2; i<=N; i++){
            for (int maxv=1; maxv<=M; maxv++){
                for(int k=1; k<=K; k++){
                    for (int m1=1; m1<=M; m1++){
                        if(m1 <= maxv)
                            dp[i][maxv][k] = (dp[i][maxv][k] + dp[i-1][maxv][k]) % mod;
                        else
                            dp[i][maxv][k] = (dp[i][maxv][k] + dp[i-1][m1][k-1]) % mod; 
                    }
                }
            }
        }
        int ans = 0;
        for (int m=1; m<=M; m++)  ans = (ans + dp[N][m][K]) % mod; 
            
        return ans;
    }    
    /*
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
    }*/
};