class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int dp[1000][1001]={};
        int ans = 0;
        for ( int i=1; i<nums.size(); i++){
            for (int j=0; j<i; j++){
                int diff = nums[i]-nums[j] + 500;
                dp[i][diff] = 1 + dp[j][diff];
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans+1;
    }
};