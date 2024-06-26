class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        for (int i=0; i< grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (i > 0) {
                    grid[i][j] += grid[i-1][j];
                    if (j > 0) grid[i][j] -= grid[i-1][j-1];
                }
                if (j > 0) grid[i][j] += grid[i][j-1];
                ans += grid[i][j] <= k;
            }
        }
        return ans;
    }
};
