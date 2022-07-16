class Solution {
public:
    int dp[51][51][51];
    int M,N,move ,mod = 1e9 + 7;
    int dirs[5] = {1,0,-1,0,1};
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M=m,N=n,move=maxMove;
        memset(dp,-1,sizeof(dp));
        return dfs(startRow, startColumn, move);
    }
    int dfs(int r, int c, int m){
        if (r<0 || c<0 || r>=M ||c >=N){
            return 1;
        }
        if (m == 0) return 0;
        if (dp[r][c][m] != -1) return dp[r][c][m];
        int ans = 0;
       
        for (int d=0; d<4;d++)
            ans = (ans + dfs(r+dirs[d], c+dirs[d+1],m-1))%mod;
       
        return dp[r][c][m] = ans;
    }
};