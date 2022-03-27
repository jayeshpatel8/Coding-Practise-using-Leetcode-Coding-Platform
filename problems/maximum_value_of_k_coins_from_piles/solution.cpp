class Solution {
public:
    int dp [1001][2001];
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        
        return dfs(piles,0,k);
    }
    int dfs(vector<vector<int>>& piles,int i, int k){
        if (i >= piles.size() || k<=0) return 0;
        if (dp[i][k] != -1 ) return dp[i][k];
        
        int ans = dfs(piles,i+1,k), sum =0;
        for (int j=0, N = min<int>(piles[i].size(), k); j< N; j++){
            sum += piles[i][j];
            ans = max (ans, sum + dfs(piles,i+1,k-j-1));
        }
        return dp[i][k] = ans;
    }
};