class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long > dp(n+1);
        for (int i=n-1; i>=0; i--){
            dp[i] = q[i][0]  + (i + q[i][1] +1  <n ? dp[i + q[i][1] + 1] : 0 );
            dp[i] = max(dp[i],dp[i+1]);
        }
        return *max_element(begin(dp), end(dp));
    }
};