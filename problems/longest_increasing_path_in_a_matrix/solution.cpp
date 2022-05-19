class Solution {
public:
    int m , n ;
    //bool vis[201][201]={};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         m = matrix.size();
        n = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(m,vector<int>(n));
        for (int i=0; i<m; i++)
            for (int j=0; j<n; j++){
                if (dp[i][j]==0)
                    ans= max(ans,dfs(i,j,dp,matrix));
            }

        return ans;
    }
    int dirs[5] = {-1,0,1,0,-1};
    int dfs(int i, int j,vector<vector<int>> &dp,vector<vector<int>>& M){
        //if (vis[i][j]) return 0;
        if (dp[i][j]) return dp[i][j];
        int ans=1;
        //vis[i][j]=1;
        for ( int d=0; d<4; d++){
            int r = i + dirs[d], c = j + dirs[d+1];
            if (r<0 || c<0 || r>=m ||c >= n || M[r][c]<=M[i][j]) continue;
            ans = max(ans, 1 + dfs(r,c,dp,M));
            
        }
        //vis[i][j]=0;
        return dp[i][j] = ans;
    }
};
