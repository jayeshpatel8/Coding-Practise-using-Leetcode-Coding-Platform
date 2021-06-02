class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for (int i= 0; i< grid.size(); i++){
            for (int j=0; j< grid[0].size(); j++){
                if(grid[i][j]){
                    
                    ans = max(ans, maxArea(grid, i, j));
                }
            }
        }
     return ans;
    }
    int maxArea(vector<vector<int>>& grid, int x, int y){
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0){
            return 0;
        }
        int ans = 1;
        grid[x][y] = 0;
        ans += maxArea(grid, x+1, y) +  maxArea(grid, x, y-1)
               +  maxArea(grid, x-1, y) +  maxArea(grid, x, y+1);
        return ans;            
    }
};