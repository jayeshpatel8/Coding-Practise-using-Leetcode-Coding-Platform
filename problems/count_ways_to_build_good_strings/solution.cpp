class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+2);        
        dp[0]=1;
        if (zero < one) swap(zero,one);
        int mod= 1e9 + 7,i=one;
        for (; i<zero; i++)
            dp[i] = dp[i-one];
        for (; i<=high; i++)
            dp[i] = (dp[i-one] + dp[i-zero])%mod;
        
        int ans = 0;
        for (int i=low; i<=high; i++){
            ans = (ans + dp[i])%mod;
        }
       
        return ans;
    }
};