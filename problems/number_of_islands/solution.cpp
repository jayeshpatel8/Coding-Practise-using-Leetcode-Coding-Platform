class Solution {
public:
    int m,n;
    int numIslands(vector<vector<char>>& grid) {
        m= grid.size(), n=grid[0].size();
        
        
         int island=0;
         for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]=='1'){
                    DFS(grid,  i, j);
                    island++;
                }
            }
         }
         return island;
    }
    void DFS (vector<vector<char>>& grid,   int i , int j){
        
        if (i<0 || j <0 || i>=m || j >=n  || '0'==grid[i][j])return;
        
        grid[i][j]='0';
        
        {
            DFS(grid,  i+1, j);
            DFS(grid,  i,j+1);
            DFS(grid,  i-1, j);
            DFS(grid,  i, j-1);
        }
    }
};