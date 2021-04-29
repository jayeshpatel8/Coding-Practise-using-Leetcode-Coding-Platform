class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size(),n=og[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][1]=1;
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (og[i-1][j-1]){
                    dp[i][j] = 0;
                }
                else{ 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];                
                }
            }
        }
        return dp[m][n];
    }
};