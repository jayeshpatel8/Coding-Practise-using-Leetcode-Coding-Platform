class Solution {
public:
int dp[1001][1001]={};
    int longestPalindromeSubseq(string s) {
        for (int i=s.size()-1; i>=0; i--){
            for (int j=i; j<s.size();j++){
                if (i==j) dp[i][j]=1;
                else{
                    if (s[i] == s[j]) dp[i][j] = 2 + dp[i+1][j-1];
                    else  dp[i][j] = max( dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
    int longestPalindromeSubseq2(string s) {
        memset(dp, -1, sizeof(dp));
        return dfs(s,0, s.size()-1);
    }
    int dfs(string & s, int i, int j){        
        if (i>=j) return i==j;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if (s[i]==s[j]) ans = 2 + dfs(s,i+1,j-1);
        else
        {
            ans =  max(ans, dfs(s,i+1,j));
            ans =  max(ans, dfs(s,i,j-1));;            
        }

        return dp[i][j] = ans;
    }
};