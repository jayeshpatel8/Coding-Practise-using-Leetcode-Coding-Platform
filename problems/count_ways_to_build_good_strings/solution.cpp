class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+2);
        int mod= 1e9 + 7;
        dp[0]=1;
        for (int i=1; i<=high; i++){
            if (i >= zero)
                dp[i] = (dp[i-zero] + dp[i] )%mod;
            if (i >= one)
                dp[i] = (dp[i-one] + dp[i])%mod;
        }
        int ans = 0;
        for (int i=low; i<=high; i++){
            ans = (ans + dp[i])%mod;
        }
       
        return ans;
    }
};