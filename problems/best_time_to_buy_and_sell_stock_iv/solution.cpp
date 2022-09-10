class Solution {
public:
    int dp[2][1001][101]={}, N ;
    
    int maxProfit(int k, vector<int>& prices) {
        N = prices.size();
        return dfs(prices,0,1,k);
    }
    int dfs(vector<int> & prices, int i,bool buy,  int k){
        if (i ==N ||k ==0) return 0;
        if (dp[buy][i][k]) return dp[buy][i][k];
        int             ans = dfs(prices,i+1,buy,k);
        ans= max(ans, (buy ? -prices[i] : prices[i])  + dfs(prices,i+1,!buy,k- !buy));     
        
        return dp[buy][i][k]  = ans;
    }
};