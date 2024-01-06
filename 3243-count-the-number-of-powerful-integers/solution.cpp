class Solution {
public:
using ll = long long;
    long long dp[17][2][2];
    string x;
    int lim ,xlen;
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string st = to_string(start-1), en=to_string(finish);
        x=s; lim=limit;
        xlen = s.size();
        memset(dp,-1,sizeof(dp));
        unsigned long long cnt1 = dfs(0,1,1,st);
        memset(dp,-1,sizeof(dp));
        unsigned long long cnt2 = dfs(0,1,1,en);

        return cnt2-cnt1;
        
    }
    unsigned long long dfs(const int i, int tight, int suf, string & str){
        int n  = str.size();
        if (n < xlen) return 0;
        if (i==n) return suf;
        if (~dp[i][tight][suf]) return dp[i][tight][suf];
        
        int hi = tight ? str[i]-'0' : lim;
        unsigned long long ans = 0;
        for (int j=0; j<=hi && j<=lim; j++){

            if ((n-i <= xlen) && ((x[xlen - (n-i)] - '0') != j) ){
                ans += dfs(i+1, tight && (j==hi), 0, str);
               
            }
            else
                ans += dfs(i+1, tight && (j==hi), suf, str);
        }
        return dp[i][tight][suf] = ans;
    }
};
