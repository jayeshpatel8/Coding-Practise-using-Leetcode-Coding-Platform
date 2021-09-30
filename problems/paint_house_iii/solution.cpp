class Solution {
public:
    int dp[101][21][101], M, N;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int t) {
        M= m, N = n;
        memset(dp,-1,sizeof(dp));
        int ans = dfs(houses, cost, 0, 0, t);
        return ans >=1e6+1 ? -1 : ans;
    }
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i,int col, int t){
        if (i>= M || t <0)
            return t == 0? 0 : 1e6+1;
        if (dp[i][col][t] != -1) return dp[i][col][t];
        if (houses[i] != 0)
            return dfs(houses, cost, i+1, houses[i], t- (col != houses[i]));
        int ans = 1e6+1;
        for (int c = 1; c <=cost[i].size(); c++){
            ans = min (ans, cost[i][c-1] + dfs(houses, cost, i+1, c, t- (col != c)));
        }
        return dp[i][col][t] = ans;
    }
};