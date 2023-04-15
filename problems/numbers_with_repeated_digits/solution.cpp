class Solution {
public:
int dp[10][2][1024];
    int numDupDigitsAtMostN(int n) {
        memset(dp,-1,sizeof(dp));
        string s = to_string(n);

        return n - dfs(s,0,1,0);
    }
    int dfs(string & s, int i , int tight , int mask){
        if (i == s.size()) return mask !=0;
        if (dp[i][tight][mask] != -1) return dp[i][tight][mask];
        int ans = 0 , dig = s[i]-'0';

        for (int d=0 , N = tight ? dig : 9; d<=N; d++){
            if ((mask & (1<<d))) continue;
            int nmask = (d|mask)==0 ? mask : mask | (1<<d);
            ans += dfs(s,i+1,tight && (d==dig),nmask);
        }

        return dp[i][tight][mask] = ans;
    }
};