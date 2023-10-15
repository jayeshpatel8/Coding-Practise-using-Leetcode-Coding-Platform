class Solution {
public:
    
    int numWays(int steps, int arrLen) {
        long max_  = min(steps, arrLen);
        vector<vector<long>> dp(steps+1,vector<long>(max_+1));
        dp[0][0]=1;
        
        for (int i=1; i<=steps; i++){
            for(int j =0; j<max_; j++){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j+1] + (j>0?dp[i-1][j-1]:0))%1000000007;
            }
            
        }
        return dp[steps][0];
    }
};