class Solution {
public:
    int dp[1001][11], N;
    int minDifficulty(vector<int>& jd, int d) {
        memset(dp,-1,sizeof(dp));
        N = jd.size();
        dfs(jd,0,d);
        return dp[0][d] >=100000 ? -1 :  dp[0][d];
    }
    int dfs(vector<int>& jd, int i, int d){
        if (i>=N || d==0){
            if (d==0 && i==N) return 0;
            return 100000;
        }
        if (dp[i][d] != -1) return dp[i][d];
        int ans = INT_MAX, ma= 0;;
        for ( int j=i; j<N-d+1; j++){
            ma= max(ma, jd[j]);
            ans= min(ans, ma+dfs(jd,j+1,d-1));
        }
        return dp[i][d]  =ans;
    }
};