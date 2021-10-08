class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int M = grid.size(), N=grid[0].size();
        long long dp[M][N][2];
        for ( int i=0; i<M; i++){
            for (int j =0; j<N; j++){
                if (i==0 && j==0){
                    dp[i][j][0] = dp[i][j][1] = grid[i][j];
                }
                else if (i==0){
                    dp[i][j][0] = dp[i][j][1] = grid[i][j] * dp[i][j-1][0] ;
                }
                else if (j==0){
                    dp[i][j][0] = dp[i][j][1] = grid[i][j] * dp[i-1][j][0] ;
                }   
                else{
                    if (grid[i][j] > 0 ){
                        dp[i][j][0] = max (dp[i][j-1][0],dp[i-1][j][0]) * grid[i][j];
                        dp[i][j][1] = min (dp[i][j-1][1],dp[i-1][j][1]) * grid[i][j];
                    }
                    else{
                        dp[i][j][0] = min (dp[i][j-1][1],dp[i-1][j][1]) * grid[i][j];
                        dp[i][j][1] = max (dp[i][j-1][0],dp[i-1][j][0]) * grid[i][j];                        
                    }
                }
            }
        }
        return dp[M-1][N-1][0] < 0 ? -1 : dp[M-1][N-1][0]% ((int)1e9 + 7);
    }
};