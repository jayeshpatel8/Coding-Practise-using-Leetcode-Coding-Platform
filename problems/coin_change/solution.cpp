class Solution {
public:
    int dp[10001]={};
    int coinChange(vector<int>& coins, int amount) {
        //memset(dp,-1,sizeof(dp));
        //int ans = dfs(coins, amount, 0);
        //return ans >=1e5 ? -1 : ans ;
        if(!amount) return 0;
        for (int j=1; j<=amount; j++){
            dp[j]=1e5;
            for (auto &c : coins){
                if (j >= c)    
                    dp[j] =  min(dp[j], dp[j - c] + 1);
            }
        }
        return dp[amount] == 1e5 ? -1 : dp[amount];
    }
    /*
    int dfs(vector<int>& coins, int amount, int i) {
        if (amount == 0) return 0;
        if (i>= coins.size() )
            return 1e5;
        if (dp[amount][i] != -1 ) return dp[amount][i];
        int ans = 1e5;
        
        if (coins[i] <= amount)
            ans = min (ans, 1  + dfs(coins,amount-coins[i],i));

        ans = min (ans, dfs(coins,amount,i+1));
                    
        return dp[amount][i] = ans;
    }
    */
};