class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int ans = 0;
        for (int r=0; r<m; r++) dp[r][0]=1;
        for (int c = 0; c <n-1; c++){
            for (int r=0; r<m; r++){
                if (dp[r][c] == 0 ) continue;
                if (r - 1 >= 0 && grid[r-1][c+1] > grid[r][c]){
                    dp[r-1][c+1] = max(dp[r-1][c+1] , dp[r][c] +1);
                }
                if (grid[r][c+1] > grid[r][c]){
                    dp[r][c+1] = max(dp[r][c+1] , dp[r][c] +1);
                }
                if (r + 1 < m && grid[r+1][c+1] > grid[r][c]){
                    dp[r+1][c+1] = max(dp[r+1][c+1] , dp[r][c] +1);
                }
            }
        }
        for (auto r : dp)
            for (auto i : r)
                ans=max(ans,i);
        return ans-1;
    }
};
