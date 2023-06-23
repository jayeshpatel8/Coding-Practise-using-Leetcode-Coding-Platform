class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int dp[1001][1001]={};
        int ans = 0;
        
        for (auto i=1; i<nums.size(); i++){
            for (int j=0; j<i; j++){
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = 1 + dp[j][diff]; 
                ans= max(dp[i][diff],ans );
            }
        }
        return ans + 1;
    }
    
};