class Solution {
public:

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N = grid[0].size();
        int dp[M*N+1][k+1] , mod = 1e9 + 7;
        memset(dp,-1,sizeof(dp));
        function<int(int,int,int)> dfs = [&](int i,int j,int rem)->int{
            if (i>=M || j>=N) return 0;
            
            if (i==M-1 && j==N-1){
                return (rem + grid[i][j]) % k == 0;
            }
            int idx = i * N + j;
            if (dp[idx][rem] != -1) return dp[idx][rem];
            int rem1 = (rem +  grid[i][j]) %k;
            int ans = ((long)dfs(i+1,j,rem1) + dfs(i,j+1,rem1))%mod;
            return dp[idx][rem] =ans;
        };
        return dfs(0,0,0);
    }
};