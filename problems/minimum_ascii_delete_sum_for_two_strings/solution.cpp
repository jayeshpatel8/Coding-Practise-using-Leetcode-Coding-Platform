

class Solution { public: int minimumDeleteSum(string s1, string s2) { int N = s1.size(), M= s2.size(), dp[N+1][M+1]; dp[0][0]=0; for (int i=1; i<=N; i++)dp[i][0]=dp[i-1][0]+s1[i-1]; for (int i=1; i<=M; i++)dp[0][i]=dp[0][i-1] + s2[i-1]; for (int i=1; i<=N; i++){ for ( int j = 1; j<=M; j++){ if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1]; else dp[i][j] = min(s1[i-1] + dp[i-1][j], s2[j-1] + dp[i][j-1]); } } return dp[N][M]; } };
