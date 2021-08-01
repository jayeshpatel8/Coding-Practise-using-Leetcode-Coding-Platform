class Solution {
public:
    int visited[501][501], m , n;
    int largestIsland(vector<vector<int>>& grid) {
         m = grid.size(), n = m;
        memset(visited,0,sizeof(visited));
        int ans=0;
        for (int i = 0; i< m; i++)
            for (int j = 0; j< n; j++)
                if (grid[i][j] && !visited[i][j]){
                    visited[i][j] = dfs(grid,i,j, i*m+j);
                    ans  = max(ans,visited[i][j]  );
                }
        for (int i = 0; i< m; i++)
            for (int j = 0; j< n; j++){
                if (grid[i][j] == 0){
                    unordered_set<int> set;
                    int idx[] = {1,0,-1,0,1};
                    for ( int k=0; k<4; k++){
                        int row = i+idx[k] , col = j+idx[k+1];
                        if (row>=0 && col>= 0 && row<m && col<n && visited[row][col]){
                            set.insert(grid[row][col]-1);
                        }
                    }
                    int sum =1;
                    for (auto num : set){
                        int row = num/m ,col = num%n;
                        sum += visited[row][col];
                    }
                    ans  = max(ans,sum);
                }
            }
        return ans;
    }
    int dfs (vector<vector<int>>& grid, int i , int  j, int id){
        if (i<0 || j< 0|| i>=m || j>=n || visited[i][j] || grid[i][j]==0) return 0;
        
        visited[i][j] =1;
        grid[i][j] = id+1;
        return  1 + dfs(grid,i+1,j,id) + dfs(grid,i,j+1,id) + dfs(grid,i-1,j,id) + dfs(grid,i,j-1,id);
        
    }
};