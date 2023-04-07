class Solution {
public:
int M,N;
    int numEnclaves(vector<vector<int>>& grid) {
        M =  grid.size(), N = grid[0].size();

        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (i==0 || j==0 || i==M-1 || j ==N-1 ){
                    if (grid[i][j]){
                        dfs(grid,i,j);
                    }
                }
            }
        }
        int ans = 0;
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                ans += grid[i][j];
            }
        }        
        return ans;
    }
    int dirs[5]={-1,0,1,0,-1};
    void dfs(vector<vector<int>>& grid, int i , int j) {
        if (i<0 || j<0 || i>= M || j >= N || !grid[i][j]) return;
        grid[i][j]=0;
        for (int d=0; d<4;  d++){
            dfs(grid,i+dirs[d],j+dirs[d+1]);
        }
    }
};