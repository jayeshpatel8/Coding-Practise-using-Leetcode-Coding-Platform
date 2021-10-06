class Solution {
public:
    int dp[71][71][71], M , N;
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        M = grid.size(), N = grid[0].size();
        return dfs(grid,0,0,N-1);
    }
    int dfs(vector<vector<int>>& grid, int r, int c1, int c2){
        if(c1 <0 || c2 <0 || c1>=N || c2 >=N) return INT_MIN;
        if (r == M) return 0;
        if (dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int ans= INT_MIN;
        for (int i=-1; i<2; i++)
            for (int j=-1; j<2; j++)
                ans = max(ans, dfs(grid,r+1,c1+i,c2+j));
        return dp[r][c1][c2] = ans + grid[r][c1] + (c1 == c2 ? 0 : grid[r][c2]);
    }
};