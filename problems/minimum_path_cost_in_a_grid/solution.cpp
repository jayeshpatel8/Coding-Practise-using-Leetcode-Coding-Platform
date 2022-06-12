class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& mc) {
        int M =grid.size(), N= grid[0].size();
        vector<vector<int>> cost(M,vector<int>(N,1e7));
        for (int i=0; i<N; i++)
            cost[0][i] = grid[0][i];
        for (int i=0; i<M-1; i++){
            for (int j=0; j<N; j++)
            {
               for (int k=0; k<N; k++)
                {
                    cost[i+1][k] = min(cost[i+1][k] ,cost[i][j] + grid[i+1][k] +mc[grid[i][j]][k] );                       
                }                
            }
        }

        int ans = INT_MAX;
        for (int j=0; j<N; j++){
            ans = min(ans, cost[M-1][j] );
        }
        return ans;
    }
};