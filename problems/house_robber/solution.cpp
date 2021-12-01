class Solution {
public:
    int rob(vector<int>& nums) {
      int N= nums.size();
      vector<int> dp(N+2,0);
      
        for ( int i = N-1; i>=0; i--)
            dp[i] = max (dp[i+1], nums[i] + dp[i+2]);
        return dp[0];
    }
};