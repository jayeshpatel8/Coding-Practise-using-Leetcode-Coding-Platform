class Solution {
public:
    int m  , n ;
    
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        m = g.size(); n = g[0].size();
        if (g[m-1][n-1] || g[0][0]) return 0;
        if (m==1 && n==1 ) return !g[m-1][n-1];
        
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        dp[1][0]=1;
        for (int i=0; i<m;i++){
            for (int j=0; j<n; j++){
                if (g[i][j])
                    dp[i+1][j+1]=0;
                else
                    dp[i+1][j+1]= dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[m][n];
    }
    int dfs(int i, int j, vector<vector<int>> &g, vector<vector<int>>& dp){
        if (i==m-1 && j==n-1) return 1;
        if (dp[i][j]) return dp[i][j];
        int ans = 0 ;
        if (i+1<m && g[i+1][j] == 0)
            ans = dfs(i+1,j,g,dp);
        if (j+1<n && g[i][j+1] == 0)
            ans += dfs(i,j+1,g,dp);
        return dp[i][j] = ans;
    }
};