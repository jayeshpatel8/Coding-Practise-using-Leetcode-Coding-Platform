class Solution {
public:
    int dp[501][501];
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return dfs(s,0,s.size()-1);
    }
    int dfs(string &s, int i, int j){
        if (i>=j) return 0;
        if (dp[i][j] != -1) return dp[i][j] ;
        int ans ;
        if (s[i]==s[j])
            ans = dfs(s,i+1,j-1);
        else{
            ans= 1 + min (dfs(s,i+1,j),dfs(s,i,j-1));
        }
        return dp[i][j]  = ans;
    }
};