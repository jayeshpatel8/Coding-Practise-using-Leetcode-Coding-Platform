class Solution {
public:
    int dp[1001][1001]={}, mod = 1e9 +7;
    int rearrangeSticks(int n, int k) {
        if (n == k) return 1;
        if (k==0) return 0;
        if (!dp[n][k])
            dp[n][k] = (rearrangeSticks(n-1, k-1) + (long)(n-1) * rearrangeSticks(n-1,k))%mod;
        return dp[n][k];
    }
};