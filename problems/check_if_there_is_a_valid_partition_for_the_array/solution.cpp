class Solution {
public:
    bool validPartition(vector<int>& nums) {
        vector<int> dp(nums.size()+1);
        dp[0]=1;
        for (auto i=1; i< nums.size(); i++){
            
            if (nums[i]==nums[i-1]){
                dp[i+1] =dp[i-1];
            }
            if (i>1){
                if ((nums[i] == nums[i-1] ) && (nums[i-1]== nums[i-2]))
                    dp[i+1]|=dp[i-2];
                else if ((nums[i]-nums[i-1] == 1) && (nums[i-1]-nums[i-2]==1)){
                    dp[i+1]|=dp[i-2];
                }
            }
        }
        return dp[nums.size()];
    }
};