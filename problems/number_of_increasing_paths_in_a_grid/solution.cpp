class Solution {
public:
int mod=1e9 + 7, M,N,ans=0;
int dirs[5] = {-1,0,1,0,-1};
vector<vector<int>> dp;
    int countPaths(vector<vector<int>>& grid) {
        M= grid.size(), N = grid[0].size();
        dp.resize(M,vector<int>(N,-1));
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                ans = (ans + dfs(grid,i,j))%mod;
        return ans;
    }
    int dfs(vector<vector<int>> &grid,int i, int j){
        if (dp[i][j] != -1) return dp[i][j];
        int cnt = 1;
        for (int d=0; d<4; d++){
            int r= i + dirs[d], c=  dirs[d+1]+j;
            if (r<0 || c<0 || r>= M || c>=N || grid[r][c] <= grid[i][j]) continue;
            cnt = (cnt + dfs(grid,r,c))%mod;
        }
        return dp[i][j]=cnt;
    }
};