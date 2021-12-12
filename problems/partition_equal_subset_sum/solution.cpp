class Solution {
public:
    //int dp[200][10001];
    
    bool canPartition(vector<int>& nums) {
        int sum  = 0;
        
        for (auto i : nums) sum += i ;
        if (sum%2) return false;
        
        vector<bool> dp(sum/2+1);
        dp[0]=1;
        for (auto i : nums){
            for (int s = sum/2 - i; s>=0; s--){
                if (dp[s])
                    dp[s+i] = true;
            }
        }
        return dp[sum/2];
        //memset(dp, -1, sizeof(dp));     
        //return dfs(nums,0,sum/2);
    }
    /*
    int dfs(vector<int>& nums, int i,int sum){
        if (i >= nums.size() || sum < 0) return sum==0;
        if (sum == 0) return true;
        if (dp[i][sum] != -1) return false;
        
        return dp[i][sum] = dfs(nums,i+1,sum) || dfs(nums,i+1,sum - nums[i]);
    }
    */
};