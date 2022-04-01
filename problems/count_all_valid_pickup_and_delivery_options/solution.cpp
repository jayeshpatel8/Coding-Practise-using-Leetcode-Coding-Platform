class Solution {
public:
    int MOD = 1e9 + 7;
    int countOrders(int n) {
        vector<vector<long>> dp (n + 1, vector<long>(n + 1, -1));
        return cnt(n,n,dp);
    }
    long cnt(int p, int d,  vector<vector<long>>& dp){
        if (d<p) return 0;
        if (dp[p][d] != -1) return dp[p][d];
        if (p== 0 && d==0){
            return dp[p][d] = 1;
        }
        long ans= 0 ;
        if (p > 0) ans= (p * cnt (p-1,d,dp)) % MOD;
        if (d > p )
            ans =  (ans + ((d-p) * cnt(p,d-1,dp)) %MOD)%MOD;
        return dp[p][d] = ans;
    }
};