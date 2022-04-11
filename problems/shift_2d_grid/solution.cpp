class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m= grid.size(), n =grid[0].size(), mn = m*n;
        k = k%mn;
        if (k%mn == 0) return grid;
        int temp = grid[0][0], start = 0 ,cnt=mn;
        vector<vector<int>> ans(m,vector<int>(n));
        for (int i=0,idx=k; i<m; i++)
            for (int j=0; j<n; j++)         
            {                
                ans[idx/n][idx%n] = grid[i][j];
                idx = (idx + 1 )%mn;
            }
        return ans;
    }
};