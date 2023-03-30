class Solution {
public:
int dp[30][30][31]={};
int n;
/* TLE
    bool isScramble(string s1, string s2) {
        n = s1.size();
        memset(dp,-1,sizeof(dp));
        function<bool(int,int,int)> dfs = [&](int i, int j, int len)    {
            if (len > n) return false;
            if (len == 1) return (dp[i][j][len] = s1[i]==s2[j])==true;
            if (dp[i][j][len] != -1) return dp[i][j][len]==true;
            for (int k=1; k<len; k++){
                if ((dfs(i,j,k) && dfs(i+k,j+k,len-k)) || (dfs(i,j+len-k,k) && dfs(i+k,j,len-k))){
                    dp[i][j][len]=true;
                    return true;
                }
            }
            return false;
        };
        return dfs(0,0,n);
    }
*/
    bool isScramble(string s1, string s2) {
        int n = s1.size();


        for (int k=1; k<=n; k++){
            for (int i=0; i+k<=n; i++)
            for (int j=0; j+k<=n; j++){
                if (k==1)
                    dp[i][j][k] = s1[i]==s2[j];
                else{
                    for (int q=1; q<k && !dp[i][j][k]; q++){
                        dp[i][j][k] = (dp[i][j][q] && dp[i+q][j+q][k-q]) || (dp[i][j+k-q][q] && dp[i+q][j][k-q]) ;
                    }
                }
            }
        }
        return dp[0][0][n];
    }
};