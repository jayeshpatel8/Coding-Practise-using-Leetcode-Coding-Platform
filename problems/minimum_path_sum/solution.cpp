class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M+1,vector<int>(N+1,100 * (M+N)));
        dp[1][0]=0;
        for (int i=1; i<=M; i++){
            for (int j=1; j<=N; j++){
                dp[i][j]= (min(dp[i][j-1],dp[i-1][j])+ grid[i-1][j-1]);
            }
        }
        return dp[M][N];
    }
};