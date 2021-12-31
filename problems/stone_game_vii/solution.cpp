class Solution {
public:
    int dp[1001][1001];
    int stoneGameVII(vector<int>& stones) {
        memset(dp,-1,sizeof(dp));
        return dfs(stones,0,stones.size()-1, accumulate(begin(stones),end(stones),0));
    }
    int dfs(vector<int>& stones, int i, int j, int sum) {
        if (i==j) return dp[i][j] = 0;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = max(sum - stones[i] - dfs(stones, i+1,j,sum-stones[i]) ,sum - stones[j] - dfs(stones, i,j-1,sum-stones[j]));
        return dp[i][j]=ans;
    }
};