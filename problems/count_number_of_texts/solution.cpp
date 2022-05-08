class Solution {
public:
    int countTexts(string keys) {
        int mod= 1e9 + 7 , n = keys.size();
        vector<int> dp(n+1);
        dp[0]=1;
        for (int i=0; i<n; i++){
            dp[i+1] = dp[i];
            auto key= keys[i];
            if (i>0 && key == keys[i-1])
                dp[i+1] = (dp[i+1] + dp[i-1])%mod;
            if (i>1 && key == keys[i-1] && key == keys[i-2])
                dp[i+1] = (dp[i+1] + dp[i-2])%mod;
            if (i>2 && (key  == '7' || key  == '9' ) && key == keys[i-1] && key == keys[i-2] && key == keys[i-3] )
                dp[i+1] = (dp[i+1] + dp[i-3])%mod;
        }
        return dp[n];
    }
};