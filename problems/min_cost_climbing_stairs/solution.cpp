

class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int N=cost.size();
        vector<long> dp(N+1,1e6+1);
        dp[0]=cost[0];        
        dp[1] = cost[1];
        for (int i=2; i<N; i++)           
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);            
        
        return min(dp[N-1] , dp[N-2]);
        
    }
};