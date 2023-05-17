class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> dp(M,vector<int>(N));
        int dirs[3] = {-1,0,1};
        for (int j=N-1; j>0; j--){
            for (int i=0; i<M; i++){
                for (auto d : dirs){
                    int r= i+d;
                    if (r<0 || r>=M || grid[i][j]<=grid[r][j-1]) continue;
                    dp[r][j-1] = max(dp[r][j-1], 1 + dp[i][j]);
                }
            }
        }
        int ret = 0;
        for (auto i=0; i<M; i++) 
            ret= max(ret, dp[i][0]);
        return ret;
    }
};