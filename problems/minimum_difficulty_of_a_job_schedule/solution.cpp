class Solution {
public:
int dp[301][11],N;
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp,-1,sizeof(dp));
        N = jobDifficulty.size();
        int ans = dfs(jobDifficulty,0,d) ;
        return ans == 1e5 ? -1 : ans;
    }
    int dfs(vector<int> & job,int i, int d){
        if (i==N || d==0){
            if (i==N && d==0) return 0;
            return 1e5;
        }
        if (dp[i][d] != -1) return dp[i][d];
        int ans = 1e5 , ma=0;
        for (int j = i; j<N-d+1; j++){
            ma = max(ma, job[j]);
            ans = min(ans, ma + dfs(job, j+1,d-1));
        }
        return dp[i][d] = ans;
    }
};
