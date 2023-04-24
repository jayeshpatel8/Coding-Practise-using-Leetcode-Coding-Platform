class Solution {
public:
    int deleteString(string s) {
        int N=  s.size();
        vector<vector<int>> lcs(N+1,vector<int>(N+1));
        vector<int> dp(N,1);
        for (int i=N-1; i>=0; i--){
          for (int j=i+1; j<N; j++){
            if (s[i] == s[j])
              lcs[i][j] = 1 + lcs[i+1][j+1];
            if (lcs[i][j] >= j-i)
              dp[i] =max(dp[i], 1 + dp[j]);
          }
        }
        return dp[0];
    }
};
