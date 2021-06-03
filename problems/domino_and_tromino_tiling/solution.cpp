class Solution {
public:
    
    int numTilings(int n) {
        unsigned int dp[n+1][3];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        dp[0][1]=1;
        dp[0][2]=1;
        
        dp[1][0]=1;
        dp[1][1]=0;
        dp[1][2]=0;
        
        for (int i=2; i<=n; i++){
            
            dp[i][0]  += dp[i-1][0];
            dp[i][0]  += dp[i-2][0];
            dp[i][0]  += dp[i-1][1];
            dp[i][0]  += dp[i-1][2];
            
            dp[i][1]  +=  dp[i-1][2];
            dp[i][2]  +=  dp[i-1][1]; 
            dp[i][1]  +=  dp[i-2][0];
            dp[i][2]  +=  dp[i-2][0];
            dp[i][0] = dp[i][0] % ((int)1e9 + 7 );
            dp[i][1] = dp[i][1] % ((int)1e9 + 7 );
            dp[i][2] = dp[i][2] % ((int)1e9 + 7 );
        }
        return dp[n][0];
    }
};