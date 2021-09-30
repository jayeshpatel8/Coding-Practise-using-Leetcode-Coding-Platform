class Solution {
public:
    int N, tsum;
    int dp[1<<16];
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1) return true;
        int sum = 0;
        for (auto i : nums) sum +=i;
        
        if (sum % k) return false;
        N  = nums.size();
        tsum = sum/k;
        memset(dp,-1,sizeof(dp));
        return dfs(nums,k-1,0);
    }
    int dfs(vector<int>& nums,  int k, int sum, int mask = 0){
        //if (mask == (1 <<N)-1) return false;
        if (dp[mask] !=  -1) return dp[mask];
        if(sum == tsum){            
            if (k == 1) return true;
            return dfs(nums,k-1,0,mask);
        }
        
        for ( int j = 0; j<N; j++){
            if ((mask & (1<<j)) == 0 && sum + nums[j] <= tsum){
                if (dp[mask| (1 <<j)] = dfs(nums,k,sum + nums[j],mask | (1 <<j)))
                    return  true;
            }
        }
        return dp[mask] = false;
    }
};