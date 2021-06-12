class Solution {
public:
    int sum , N;
    int dp1[1002][1002];
    int stoneGameVII(vector<int>& stones) {
        N = stones.size();
        //sum = accumulate(begin(stones),end(stones),0);
        int dp[N+2][N+2];
        memset(dp,0,sizeof(dp));
        int pre[N+1];
        pre[0] =0;
        for (int i=1; i<=N; i++) pre[i] = pre[i-1] + stones[i-1];
        for (int l=N; l>=1; l--){
            for (int r=l; r<=N; r++)
                dp[l][r] = max ( pre[r]-pre[l] - dp[l+1][r], pre[r-1]-pre[l-1]-dp[l][r-1]);
        }
        return dp[1][N];
        //return dfs(stones,0,N-1,sum);;
    }
    int dfs(vector<int>& stones, int s, int e,  int sum){
        if (s == e){
            return dp1[s][e] = 0;
            
        }
        if (dp1[s][e] != -1) return dp1[s][e];
        
        
        return dp1[s][e] = sum - min (stones[s] + dfs(stones,s+1,e,sum-stones[s]),
                                      stones[e] + dfs(stones,s,e-1,sum-stones[e])
                              );
    }
};