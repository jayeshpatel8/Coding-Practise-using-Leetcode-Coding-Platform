
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r =grid.size(),c=grid[0].size();
        int csum=0,msum=INT_MAX;
        int dp[c];
        dp[0]=grid[0][0];
        for (int i=1; i<c; i++)
            dp[i] = dp[i-1]+grid[0][i];
        for (int i=1; i<r; i++){
            dp[0]+=grid[i][0];
            for (int j=1; j<c; j++)
            {
                dp[j] = min(dp[j-1],dp[j])+grid[i][j];                        
            }
        }
        return dp[c-1];
    }
};