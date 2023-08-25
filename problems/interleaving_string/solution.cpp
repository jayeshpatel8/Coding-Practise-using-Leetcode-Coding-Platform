class Solution {
public:
int dp[101][101];
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return dfs(s1,s2,s3,0,0,0);
    }
    bool dfs(string &s1, string &s2, string &s3, int i, int j,int k){
        if (k== s3.size() ){
            return i==s1.size() && j==s2.size();
        }
        if (dp[i][j] != -1) return dp[i][j];
        bool ans = 0;
        if (i<s1.size() && s1[i]==s3[k]) ans = dfs(s1,s2,s3,i+1,j,k+1);
        if (j<s2.size() && s2[j]==s3[k]) ans |= dfs(s1,s2,s3,i,j+1,k+1); 
        return dp[i][j]=ans;
    }
};