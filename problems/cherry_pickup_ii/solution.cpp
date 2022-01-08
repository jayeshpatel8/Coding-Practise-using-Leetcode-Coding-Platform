class Solution {
public:
    int dp[71][71][71];
    int m , n;
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        m = grid.size(),n = grid[0].size();
        return dfs(grid,0,0,n-1);
    }
    int dfs(vector<vector<int>>& g, int i, int j, int j1){
        if (j<0 || j1<0 || j>=n || j1>=n) return INT_MIN;
        if (i==m) return 0;

        if (dp[i][j][j1] != -1) return dp[i][j][j1];
        int ans = INT_MIN;
        for (int k=-1; k<2; k++){
            for (int k1=-1; k1<2; k1++)
                    ans = max(ans, dfs(g,i+1,j+k,j1+k1));         
        }
        return dp[i][j][j1] = ans + g[i][j] + (j!=j1 ?g[i][j1] : 0) ;
            
    }
}; 