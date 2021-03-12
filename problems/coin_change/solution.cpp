class Solution {
public:
    int dp[10005];
    int coinChange(vector<int>& coins, int amount) {
        
        if(!amount) return 0;

        for(int i=0; i< 10005; i++) dp[i]=10001;
        dp[0]=0;
        for(int i=1; i<=amount; i++)
        {
            for(auto coin : coins){
                if(coin<= i)
                    dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
        
        return dp[amount]==10001?-1:dp[amount];
    }

};