class Solution {
public:
    long long mostPoints(vector<vector<int>>& que) {
        vector<long> dp(que.size()+1);
        for (int N=que.size(),i=N-1; i>=0;i--){
            if (i+que[i][1]+1 <N){
                dp[i]= dp[i+que[i][1]+1];
            }
            dp[i] = max(dp[i]+que[i][0],dp[i+1]);
        }
        return dp[0];
    }
};