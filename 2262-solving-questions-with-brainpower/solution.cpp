class Solution {
public:
    long long mostPoints(vector<vector<int>>& que) {
        using ll = long long;
        vector<ll> dp(que.size()+1);

        for (int i=que.size()-1; i>=0; i--){
            ll p = que[i][0], skip= que[i][1];
            if (i + skip +1< que.size()){
                dp[i] = dp[i+skip+1];  
            }
            dp[i] = max(dp[i] + p,  dp[i+1]);
        }
        return dp[0];
    }
};
