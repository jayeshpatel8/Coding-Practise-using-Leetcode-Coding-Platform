class Solution {
public:
    int dp[51][51][11];
    int A[51][51]={}, mod =  1e9 +7,M,N;
    int ways(vector<string>& pizza, int k) {
        
         M = pizza.size(), N = pizza[0].size();
        for(int i= M-1; i>=0; i--)
            for(int j=N-1;j>=0; j--){
                A[i][j] = (pizza[i][j] == 'A') + A[i][j+1] + A[i+1][j]-A[i+1][j+1];
            }
        memset(dp,-1,sizeof(dp));
        return dfs(pizza, k-1, 0, 0);
    }
    int dfs(vector<string>& pizza, int k, int r, int c){
        if(A[r][c] == 0) return 0;
        if(k==0) return 1;
        if(dp[r][c][k] != -1) return dp[r][c][k];
        int ans = 0;
        
        for(int r1 = r+1; r1<M; r1++){
            if(A[r][c] == A[r1][c]) continue;
            ans = (ans + dfs(pizza, k-1, r1, c))%mod;
        }
        for(int c1 = c+1; c1<N; c1++){
            if(A[r][c] == A[r][c1]) continue;
            ans = (ans + dfs(pizza, k-1, r, c1))%mod;
        }        
        return dp[r][c][k] =ans;
    }
};