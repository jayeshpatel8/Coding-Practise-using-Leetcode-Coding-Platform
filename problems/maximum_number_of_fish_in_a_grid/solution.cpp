class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;

        for (auto i = 0; i<grid.size(); i++)
            for (auto j = 0; j < grid[0].size(); j++ )
                if (grid[i][j])
                    ans= max(ans,dfs(grid,i,j));
        return ans;         
    }
    int dir[5]={-1,0,1,0,-1};
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if (i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || !grid[i][j]) return 0;        
        int ans = grid[i][j];
        grid[i][j]=0;
        for (int d=0; d<4;d++){
            int i1= i+ dir[d], j1=j+dir[d+1];
            ans += dfs(grid,i1,j1);
        }
        return ans;
    }
};