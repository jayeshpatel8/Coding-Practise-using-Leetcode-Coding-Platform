class Solution {
public:
    int dp[101][21][101], M, N;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans;
        M=m,N=n;
        ans = dfs(houses,cost,0,0,target);
        return ans > 1e6 ? -1 : ans;
    }
    int dfs(vector<int>& h, vector<vector<int>>& cost, int i, int j, int k){

         if (i >=M || k < 0)
        return k == 0 ? k : 1e6 + 1;
        if (h[i] !=0 )
            return dp[i][j][k] = dfs(h,cost,i+1,h[i],k - (j!= h[i]));
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int ans =  1e6 + 1;
        for (int j1 = 1; j1 <= N; j1++){
            ans = min(ans, cost[i][j1-1] + dfs(h,cost,i+1,j1,k - (j != j1)) );
        }
        return dp[i][j][k] = ans;
    }
};