class Solution {
public:
    vector<vector<int>> dp;
    int countPyramids(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size(), res=0;
         dp.resize(M,vector<int>(N,-1));
        for (int i=0; i<M-1; i++ ){
            for (int j=1; j<N-1; j++){
                if (grid[i][j])
                    res +=  count(grid,i,j);
            }
        }
        dp = vector<vector<int>>(M,vector<int>(N,-1));
        reverse(grid.begin(), grid.end());
        for (int i=0; i<M-1; i++ ){
            for (int j=1; j<N-1; j++){
                if (grid[i][j])
                    res +=  count(grid,i,j);
            }
        }
        return res;
    }
    int count(vector<vector<int>>& grid, int i, int j){
        if ( j<0 || j >=grid[0].size() || !grid[i][j]) return -1;
        if (dp[i][j] != -1) return dp[i][j];
        
        if (i+1>= grid.size() || !grid[i+1][j]) return dp[i][j]=0;
        
        return dp[i][j] = 1 + min(count(grid,i+1,j-1), count(grid,i+1,j+1));
    }
};