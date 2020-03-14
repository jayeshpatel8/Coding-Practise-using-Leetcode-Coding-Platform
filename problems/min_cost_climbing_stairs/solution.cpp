class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(2,0);
        int n=cost.size();
        if (n==1)  return cost[0];
        dp[0]=cost[0];
        dp[1]=cost[1];
        for (int i=2; i<n;i++)
        {
            dp[i%2] = min(dp[0],dp[1])+cost[i];
        }
        return min(dp[0],dp[1]);
    }
};