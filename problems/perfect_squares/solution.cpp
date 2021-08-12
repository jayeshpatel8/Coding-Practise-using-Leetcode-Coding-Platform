class Solution {
public:
    int dp[10001];
    int numSquares(int n) {
        int ps = sqrt(n);
        /*
        dp[0]=0;
        for ( int i=1; i<=n; i++){
            int ans = INT_MAX;
            for (int j = 1 , k = j*j;  k <= i && j<=ps; k  =  ++j * j ){
                ans = min(ans, 1 + dp[i-k]);
            }
            dp[i] = ans;
        }
        return dp[n];
        */
        ///* memo is faster
        memset(dp,-1,sizeof(dp));
        return count(n,ps);
        //*/
        
    }
    int count(int n, int ps){
        if (n==0 ) return 0;
        if(dp[n] != -1) return dp[n];
        if (ps == 1) return n;
        if (n<4) return n;
        int ans=INT_MAX;
        
        for ( int i = ps; i>0; i--){
            int num = i*i;
            if (num <= n)
                ans = min(ans, n/num + count(n%num,ps-1));
        }
        return dp[n]= ans;
    }
};