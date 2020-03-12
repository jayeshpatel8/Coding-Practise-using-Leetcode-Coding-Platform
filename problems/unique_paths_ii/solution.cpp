class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
    int r = o.size(),c=o[0].size();
    vector<vector<long>> dp(r+1,vector<long>(c+1,0));
    dp[0][1]=1;
    for (int i=1; i<=r; i++)
        for (int j=1; j<=c; j++)        
        {
            if (o[i-1][j-1] ) {continue;}
            dp[i][j]= dp[i][j-1] + dp[i-1][j];
        }
        return dp[r][c];
    }
};