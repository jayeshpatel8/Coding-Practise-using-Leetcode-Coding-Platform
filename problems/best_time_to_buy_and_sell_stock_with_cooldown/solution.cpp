class Solution {
public:
    int dp[5001][2];
    int maxProfit(vector<int>& prices) {
        int  N =  prices.size();
        if (N<2) return 0;
        dp[0][0]=0,                           dp[0][1]=(-prices[0]);
        
        dp[1][0]=max(0,prices[1]-prices[0]),  dp[1][1]=max(-prices[0],-prices[1]);
        for ( int i=2; i<N; i++){
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]); // buy
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]); // sell
        }
        return (dp[N-1][0]);
        /* memo 
        memset(dp,-1,sizeof(dp));
        profit(prices); // Memo
        int ans = 0;
        for ( int i=0; i<N; i++)
            ans = max(ans, dp[i][1]);
        return ans;
        */
    }
    int profit(vector<int>& prices, int i=0, int buy=1){
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        
        int ans  = 0 ;
        if (buy)
            ans = max (profit(prices, i+1, !buy) - prices[i], profit(prices, i+1, buy));
        else
            ans = max (prices[i] + profit(prices, i+2, !buy), profit(prices, i+1, buy));
        
        return dp[i][buy] = ans;
    }
};