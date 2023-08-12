class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[101][101]={};
        if (grid[0][0] || grid[m-1][n-1]) return 0;
        
        dp[0][1]=1;
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                if (grid[i-1][j-1]) continue;
                dp[i][j]=dp[i-1][j];
                dp[i][j]+=dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};