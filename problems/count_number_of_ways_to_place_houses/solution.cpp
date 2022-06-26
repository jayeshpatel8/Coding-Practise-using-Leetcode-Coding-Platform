class Solution {
public:
    int countHousePlacements(int n) {
        long dp[2] ={1,1};
        int mod = 1e9 +7;
        for (int i=2; i<=n; i++){
            long a  = (dp[0] + dp[1]) % mod;
            long b  = (dp[0] ) % mod;
            dp[0]=a,dp[1]=b;
        }
        return (dp[0]+dp[1]) * (dp[0]+dp[1])%mod;
    }
};