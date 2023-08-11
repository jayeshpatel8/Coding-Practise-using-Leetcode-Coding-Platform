class Solution {
public:
    int dp[5001][300];
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return dfs(amount,coins);
    }
    int dfs(int amt, vector<int>& coins,int i=0) {
        if (amt==0) return 1;
        if ( amt < 0 || i== coins.size()) return 0;
        if (dp[amt][i] != -1) return dp[amt][i];
        dp[amt][i] = dfs(amt-coins[i],coins,i) + dfs(amt,coins,i+1);
        return dp[amt][i];
    }
};