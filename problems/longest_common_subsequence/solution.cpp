class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string t1, string t2) {
       
        for (int i=t1.length()-1; i>=0; i--){
            for (int j=t2.length()-1; j>=0; j--){
                if (t1[i]==t2[j]) 
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};