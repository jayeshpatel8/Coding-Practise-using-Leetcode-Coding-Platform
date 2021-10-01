class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m = t1.size()+1, n =  t2.size()+1;
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=t1.size(); i++){
            for(int j=1; j<=t2.size(); j++){
                if (t1[i-1] == t2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};