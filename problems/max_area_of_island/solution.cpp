class Solution {
public:
    bool vis[51][51]={};
    int M,N;
    int dirs[5] = {1,0,-1,0,1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        M = grid.size(), N = grid[0].size();

        int ans = 0;
        for (int i=0; i<M; i++)
            for (int j=0; j<N; j++)
                ans= max(ans , dfs(grid,i,j));
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || j <0 ||i >=M ||j >= N || grid[i][j]==0 || vis[i][j] ) return 0;
        vis[i][j] = true;
        int ans = 1;
        for (int k=0; k<4; k++){
            int r = i + dirs[k], c = j + dirs[k+1];
            ans+=  dfs(grid,r,c);
        }

        return  ans;
    }
};