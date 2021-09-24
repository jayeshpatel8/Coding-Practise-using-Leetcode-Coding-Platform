class Solution {
public:
    int dp[30][6000];
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return dfs(stones);
    }
    int dfs(vector<int>& stones, int i=0, int sum=0){
        if(i>= stones.size()) return sum < 0 ? INT_MAX : sum;
        if(dp[i][sum + 3000] != -1) return dp[i][sum + 3000];
        int ans = min (dfs(stones, i+1, sum + stones[i]), dfs(stones, i+1, sum - stones[i]));
        return dp[i][sum + 3000] = ans;
    }
};