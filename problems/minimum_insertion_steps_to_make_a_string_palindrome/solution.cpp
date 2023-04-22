class Solution {
public:
    int minInsertions(string s) {
        int N=  s.size();
        vector<vector<int>> dp(N+1,vector<int>(N+1));
        for (int i=0; i<=N; i++) 
            dp[i][i]=0;
        for (int i=2; i<=N; i++){
            for (int j=0,k=i-1; k<N; k++,j++ ){
                if (s[j]==s[k]) dp[j][k] = dp[j+1][k-1];
                else
                    dp[j][k] =  1 + min(dp[j+1][k], dp[j][k-1]);                
            }
        }
        return dp[0][N-1];
    }
};