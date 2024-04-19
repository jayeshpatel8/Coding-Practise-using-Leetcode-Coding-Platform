class Solution {
public:
    int m,n,ans = 0, dirs[5] = {-1,0,1,0,-1};
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n =grid[0].size();
        for (int i=0; i<m; i++){
            for (int j= 0; j<n; j++)
                if (grid[i][j]=='1')
                    ++ans, dfs(grid, i, j);
        }
        return ans;
    }
    void dfs (vector<vector<char>>& grid, int i, int j) {        
        
        grid[i][j]='0';
        for (int d = 0; d<4; d++){
            int i1=i+dirs[d], j1 = j+dirs[d+1];
            if (i1<0 || j1<0|| i1>=m || j1>=n || '0' == grid[i1][j1]) continue;
                dfs(grid,i1,j1);
        }        
    }
};
