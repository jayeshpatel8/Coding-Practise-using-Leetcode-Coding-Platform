class Solution {
public:
    int dp[5001][2] , N;
    
    int maxProfit(vector<int>& prices) {
        N = prices.size();
        memset(dp,-1,sizeof(dp));
        return dfs(prices,0,1);
    }
    int dfs(vector<int>& prices, int i, int buy){
        if (i >= N) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        int ans = dfs(prices, i+1, buy), ans2;
        if (buy){
            ans2 = -prices[i] + dfs(prices, i+1, 0);
        }
        else
            ans2 = prices[i] + dfs(prices, i+2, 1);
        return dp[i][buy] = max(ans,ans2);
    }
};