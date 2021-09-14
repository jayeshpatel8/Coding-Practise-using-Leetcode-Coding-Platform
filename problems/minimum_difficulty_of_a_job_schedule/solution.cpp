class Solution {
public:
    int N;
    int dp[11][301];
    int minDifficulty(vector<int>& job, int d) {
        N = job.size();
        if(N < d) return -1;
        dp[0][0]=job[0];
        
        for(int j = 1; j < N; ++j){
            dp[0][j] = max(job[j], dp[0][j - 1]);
        }
        for (int i=1; i<d; i++){
            for(int j=i; j<N; j++){
                int c_max =0;
                dp[i][j]=1e6;
                for (int k=j; k>=i; k--){
                    c_max = max(c_max, job[k]);
                    dp[i][j] = min (dp[i][j], c_max + dp[i-1][k-1]);                    
                }
            }
        }
        return dp[d-1][N-1];
        //memset(dp,-1,sizeof(dp));
        //int ans = dfs(job, d,N-1);
       // return ans == 1e6 ? -1 : ans;
    }
    /*
    int dfs(vector<int>& job, int d, int i){
        if (i== -1 && d == 0) return 0;
        if ( d == 0 ||i ==-1) return 1e6;
        
        if (dp[d][i] != -1) return dp[d][i];
        int ans = 1e6;
        int c_max = job[i];
        for(int j  = i; j>=0; j--){
            c_max = max(c_max, job[j]);
            ans = min (ans, c_max + dfs(job,d-1,j-1));
        }
        return dp[d][i] = ans;
    }*/
};