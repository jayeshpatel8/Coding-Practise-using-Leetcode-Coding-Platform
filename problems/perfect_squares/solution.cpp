class Solution {
public:
    int numSquares(int n) {
        vector<int> sq, dp(n+1,INT_MAX);
        for (int i=1; i*i<=n; i++){
            sq.push_back(i*i);            
        }
        dp[0]=0;
        for (int i=1; i<=n; i++){
            for (auto s : sq){
                if (s <= i)
                    dp[i] = min(dp[i], dp[i-s]+1);
            }
        }
        return dp[n];
    }
    /*
    int dp[10001];
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(n,sqrt(n));
    }
    int dfs(int n , int psq){
        if (n == 0) return 0;
        if (dp[n] != -1 ) return dp[n];
        if (psq == 1 || n <4) return n;
        dp[n]=INT_MAX;
        for ( int sq = psq; sq >0; sq--){
            int num = sq * sq;
            if (num <= n)
                dp[n] = min(dp[n], n / num + dfs(n%num, sq-1));
        }
        return dp[n];
    }
    */
};