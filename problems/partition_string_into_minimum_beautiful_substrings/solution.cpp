class Solution {
public:
int dp[15];
    int minimumBeautifulSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        auto ans = dfs(s,0);
        return ans >15 ? -1 : ans;
    }
    int dfs(string & s, int i){
        if (i==s.size()) return 0;
        if (dp[i] != -1) return dp[i];
        if (s[i]=='0') return dp[i] = 16;
        int ans = 16;
        for (int j=i, n = 0; j<s.size(); j++){
            n =  n<<1;
            n |= (s[j]=='1');
            if (15625%n ==0) 
                ans = min(ans, 1 + dfs(s,j+1));
        }
        return dp[i] =ans;
    }
};