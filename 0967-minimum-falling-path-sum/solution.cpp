class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n = matrix.size();
      vector<vector<int>> dp(n,vector<int>(n,10001));
        for (int i=0; i<n; i++) dp[0][i]  = matrix[0][i];
      for (int i=0; i<n-1; i++){
          for (int j=0; j<n; j++){
              
              for (int k=-1,j1=j+k; k<2&& j1<n; k++,j1++){
                  if( j1>=0) dp[i+1][j1] = min(dp[i+1][j1],matrix[i+1][j1]+dp[i][j]);
              }
          }
      }
        return *min_element(begin(dp[n-1]),end(dp[n-1]));
    }
};
