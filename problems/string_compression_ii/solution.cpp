class Solution {
public:
int dp[101][101];
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return dfs(s,0,k);
    }
    int dfs(string &s, int i, int K){
        int k = K;
        if (s.size() - i <= k) return 0;
        if (dp[i][k] >= 0 ) return dp[i][k];
        int ans = k ? dfs(s,i+1,k-1):1000 ,c = 1;
        for (int j=i+1; j<=s.size() ; j++){
            ans = min(ans, dfs(s,j,k) + 1 + (c >= 100 ? 3 : (c>=10?2 : (c >1 ? 1 : 0))));
            if (j==s.size()) break;
            if (s[i]==s[j]) c++;
            else if (--k <0)break;
        }
        return dp[i][K] = ans;
    }
};