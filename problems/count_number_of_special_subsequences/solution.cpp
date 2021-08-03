class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        vector<int> dp(4,0);
        const int  mod = 1e9 + 7;
        //if (nums[0]==0) 
        dp[0]=1;
        for ( int i=0; i<nums.size(); i++){
            int cur = nums[i] ,next=cur+1;
            dp[next] = (2UL * dp[next] + dp[cur])%mod ;
        }
        return dp[3];
    }
};