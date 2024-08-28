class Solution {
public:
    int R ,C;
    int dir[5] = {-1,0,1,0,-1};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        R = grid1.size(), C = grid1[0].size();
        int ans = 0;
        for (int i=0; i<R; i++)
            for (int j=0; j<C; j++){
                if (grid2[i][j] == 1 && grid1[i][j]){
                    ans += dfs(grid1, grid2,i, j);
                }
            }
        return ans;
    }
    
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c) {
        if (r<0 || c < 0|| r >= R || c >= C ||!grid2[r][c]) return 1;

        int ans = grid2[r][c] && grid1[r][c];
        {
            
            grid2[r][c] = 0;
            for (int i=0; i<4; i++){
                ans &= dfs(grid1, grid2, r + dir[i], c + dir[i+1]);
            }
            return ans;
        }
    }
};
