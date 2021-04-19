class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<uint64_t> dp(target+1,0);
        dp[0]=1;
        // [1,2,3], target = 4
        // 
        for (int t=1; t<=target; t++){
            for (auto i: nums){                
                if (i<=t){
                    dp[t] += dp[t-i];
                }                
            }
        }
        return dp[target];
    }
};