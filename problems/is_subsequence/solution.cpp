class Solution {
public:
    bool isSubsequence(string s, string t) {
        int M = s.size(), N = t.size();
        vector<vector<int>> dp(M+1, vector<int>(N+1));
        
        for ( int i = M-1; i>=0; i--)
        {
            for(int j = N-1; j>=0;j--){
                if (s[i] == t[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else 
                    dp[i][j] = dp[i][j+1]; //max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0]==M;
    }
};