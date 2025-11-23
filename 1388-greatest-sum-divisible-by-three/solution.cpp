class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int dp[3]={};
        
        for ( auto i : nums){
            int x = i + dp[0];
            int y = i + dp[1];
            int z = i + dp[2];
            dp[x%3] = max(dp[x%3], x);
            dp[y%3] = max(dp[y%3], y);
            dp[z%3] = max(dp[z%3], z);
        }
        return dp[0];
    }
};
