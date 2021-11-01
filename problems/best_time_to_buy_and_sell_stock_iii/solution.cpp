class Solution {
public:
    int dp[100001][2][2];
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return dfs(prices,0,1,0);
    }
    int dfs(vector<int>& prices, int i, bool buy,int cnt){
        if (i>= prices.size() || cnt >= 2) return 0;
        if (dp[i][buy][cnt] != -1) return dp[i][buy][cnt];
        int ans = dfs(prices,i+1,buy,cnt);
        if (buy)
            ans = max(ans, -prices[i] + dfs(prices,i+1,0,cnt) );
        else
            ans = max(ans, prices[i] + dfs(prices,i+1,1,cnt+1) );
        
        return dp[i][buy][cnt] = ans;
        
    }
};