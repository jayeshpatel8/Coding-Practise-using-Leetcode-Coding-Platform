class Solution {
public:

    int dieSimulator(int n, vector<int>& rollMax) {
        /* draw the how the table is getting filled for n=0 to n=1 and 
            it shows that 
             dp[i][j] = (dp[i][j] + dp[i][6] (previous sum of n) - dp[i-k][j] (current selected j) + mod)%mod;    
             where dp[i][6] is ans for i =>[0 - n] for all j
        */
        int ans = 0, mod = 1e9 + 7;
        vector<vector<long>> dp(n+1, vector<long>(7, 0));
        vector<long> sum(n+1, 0);
        sum[0]=1;dp[0][6]=1;
        for ( int i =1; i<=n; i++){
            for ( int j =0; j<6; j++){
                for ( int k =1; k<=rollMax[j] && i-k >=0; k++){
                    dp[i][j] = (dp[i][j] + dp[i-k][6] - dp[i-k][j] + mod)%mod;                     
                }
                dp[i][6]=  (dp[i][6] + dp[i][j])%mod;
            }            
        }
        return dp[n][6];
    }

    /*
    int dp[5001][7][16]={} , mod = 1e9 + 7;
    int dieSimulator(int n, vector<int>& rollMax) {
        int ans = 0;
         memset(dp,-1,sizeof(dp));
        for ( int i =0; i<6; i++){
            ans = (ans + dfs(n-1, rollMax, i, 1))%mod;
        }
        return ans;
    }
    int mod = 1e9 + 7;
    int dfs(int n , vector<int>& rollMax, int last, int consecutive ){
        if(n <= 0) return 1;
        if (dp[n][last][consecutive] != -1) return dp[n][last][consecutive];
        int ans = 0;
       if ((consecutive ) < rollMax[last] )
           ans = (ans + dfs(n-1, rollMax, last, consecutive + 1))%mod;   
        for ( int i =0; i<6; i++){
            if ( last != i)
                ans = (ans + dfs(n-1, rollMax, i, 1))%mod;
        }
     
        return dp[n][last][consecutive]=ans;
    }
*/
};
