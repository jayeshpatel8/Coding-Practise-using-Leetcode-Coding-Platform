class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len < 2) return 0;
        int dp[len+1], min=prices[0];
        dp[0]=0;
        for (int i = 1; i<= len; i++)
        {
            if (prices[i-1]< min) min= prices[i-1];
            dp[i] = max(prices[i-1]-min, dp[i-1]);
        }
        int max=prices[len-1];
        int res=-1;
        for (int i = len; i>0; i--)
        {
            if (prices[i-1]> max) max= prices[i-1];
            dp[i] = std::max(max-prices[i-1] + dp[i-1], dp[i]);
            if (dp[i]>res) res=dp[i];
        }        
        return res;
    }
};