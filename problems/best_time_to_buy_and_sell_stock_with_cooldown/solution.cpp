class Solution {
public:
int dp[5001][2] ={}, N;

    int maxProfit(vector<int>& prices) {
        N = prices.size();
        //memset(dp,0,(N+2)*sizeof(int)*2);
        for (int i=N-1; i>=0; i--){
            for (int sell=0; sell<2; sell++){
                int ans =  dp[i+1][sell];
                if (sell)
                    ans  = max(ans, prices[i] + dp[i+2][0]);
                else
                    ans  = max(ans,-prices[i] + dp[i+1][1]); 
                dp[i][sell]=ans;
            }
        }
        return dp[0][0];
    }
    int dfs(vector<int>& prices, int i, bool sell) {
        if (i >= N) return 0;
        if (dp[i][sell] != -1) return dp[i][sell];

        int ans =  dfs(prices, i+1,sell);
        if (sell)
            ans  = max(ans, prices[i] + dfs(prices,i+2,0));
        else
            ans  = max(ans,-prices[i] + dfs(prices,i+1,1));        
        
        return dp[i][sell]=ans;
    }
};