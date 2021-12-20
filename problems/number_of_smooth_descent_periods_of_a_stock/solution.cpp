class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        vector<long long> dp(n);
        long long ans = n;
        for (int i=1; i<n; i++){
            if (prices[i] == prices[i-1]-1 ){
                dp[i] = 1 + dp[i-1];
                ans += dp[i];
            }
        }
        return ans;
    }
};