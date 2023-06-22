class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int ans = 0;
        
        int prevBuy = -prices[0], prevSell=0;
        for (int i=1; i<prices.size(); i++){
            int curBuy =max(-prices[i] + prevSell , prevBuy);
            int curSell =max( prices[i] - fee + prevBuy , prevSell);
            prevBuy= curBuy;
            prevSell=curSell;
        }
        return prevSell;
    }
    int maxProfit3(vector<int>& prices, int fee) {
        int ans = 0;
        vector<vector<int>> dp(prices.size(),vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i=1; i<prices.size(); i++){
            dp[i][0] =max(-prices[i] + dp[i-1][1] , dp[i-1][0]);
            dp[i][1] =max( prices[i] - fee + dp[i-1][0] , dp[i-1][1]);
        }
        return dp[prices.size()-1][1];
    }
    int maxProfit2(vector<int>& prices, int fee) {
        int ans = 0;
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        function<int(int , bool)> dfs= [&](int i, bool buy){
            if (i >=prices.size()) return 0;
            if (dp[i][buy] != -1) return dp[i][buy];
            
            if (!buy)
                return dp[i][buy] =max((-prices[i] + dfs(i+1,!buy)) , dfs(i+1,buy));
            else 
                return dp[i][buy] =max(( prices[i] - fee + dfs(i+1,!buy)) , dfs(i+1,buy));


        };
        return dfs(0,0);
    }
};