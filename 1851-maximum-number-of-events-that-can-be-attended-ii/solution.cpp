class Solution {
public:
int  N ;
    int maxValue(vector<vector<int>>& events, int k) {
        N = events.size();
        sort(events.begin(), events.end());
        
        vector<vector<int>>dp(N+1,vector<int>(k+1,-1));
        return dfs(events,0,k,dp);
    }
    int dfs(vector<vector<int>>&e , int i, int k,vector<vector<int>>&dp){
        if (i>=N || k==0) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        
        auto j = upper_bound(begin(e) + i, end(e), e[i][1], 
        [](int t, const vector<int> &v) {return v[0] > t;}) - begin(e);
        return dp[i][k] = max(dfs(e,i+1,k,dp), e[i][2] + dfs(e,j,k-1,dp));
    }
};
