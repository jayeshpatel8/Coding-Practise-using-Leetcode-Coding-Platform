class Solution {
public:
    int cnt,N,M, dirs[5]= {-1,0,1,0,-1};;
    int uniquePathsIII(vector<vector<int>>& grid) {
        N = grid.size(), M=grid[0].size();
        int si,sj; cnt = N*M-1;
        for (int i=0; i<N; i++)
            for (int j=0;j<M; j++){ 
                if (grid[i][j] == 1)
                    si = i, sj = j;
                else if (grid[i][j]==-1)cnt--;
            }
         return dfs(grid,si,sj);       
    }
    int dfs (vector<vector<int>>& grid, int i, int j){
            if (i<0 || i>=N || j<0 || j>=M || grid[i][j] < 0) return 0;
            
            if (grid[i][j] == 2) return !cnt;

            grid[i][j]=-1; 
            int ans = 0;
            cnt--;
            for (int d=0; d<4; d++){
                ans += dfs(grid, i + dirs[d], j + dirs[d+1]);
            }
            grid[i][j]=0;
            cnt++;
            return ans;
        };    
};