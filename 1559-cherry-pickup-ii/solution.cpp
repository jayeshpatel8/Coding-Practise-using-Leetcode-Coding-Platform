class Solution {
public:
    int dp[71][71][71];
    int m,n;
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(grid,0,0,n-1);
    }
    int dfs(vector<vector<int>>& grid, int i, int j, int j1) {
        if (j<0 || j1<0 || j >=n ||j1 >=n) return INT_MIN;
        if (m==i) return 0;

        if (dp[i][j][j1] != -1) return dp[i][j][j1];
        int ans = INT_MIN;
        for (int k=-1; k<2; k++)
            for (int k1=-1; k1<2; k1++)
                ans = max(ans, dfs(grid,i+1,j+k,j1+k1));
        return dp[i][j][j1] =  ans + grid[i][j] + (j1!=j? grid[i][j1] : 0 );
    }
};
