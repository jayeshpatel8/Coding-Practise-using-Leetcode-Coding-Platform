class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        // total sum has to be even
        int total = 0;
        for (auto i : nums) total +=i;
        if (total%2) return false;
        // find subset sum of total/2
        vector<bool> dp(total/2+1);
        dp[0]=true;
        for (auto i : nums){
            for (int sum=total/2-i; sum>=0; sum--){
                if (dp[sum] ){
                    dp[sum+i]=true;
                }
            }
        }
        return dp[total/2];
    }
};