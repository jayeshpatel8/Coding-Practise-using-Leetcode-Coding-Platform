class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int M= dun.size(), N = dun[0].size();        
         vector<vector<int>> dp(M+1,vector<int>(N+1,INT_MAX));
        dp[M - 1][N] = 1;
        dp[M][N - 1] = 1;
        for ( int i = M-1; i>=0; i--)
        {
            for ( int j = N-1; j>=0; j--)
                    dp[i][j] = max(min(dp[i][j+1],dp[i+1][j])-dun[i][j],1);
        }
        return dp[0][0];
    }
};