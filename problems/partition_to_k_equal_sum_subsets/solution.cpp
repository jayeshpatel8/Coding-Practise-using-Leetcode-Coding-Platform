class Solution {
public:
    int ksum = 0, N;
    int dp[(1<<16)];
    bool canPartitionKSubsets(vector<int>& nums, int k) {     
        for (auto i : nums) ksum +=i;
        if (ksum % k) return false;
        ksum /=k;
        N=nums.size();
        memset(dp,-1,sizeof(dp));
        return partsum(nums,0,k,0);
    }
    bool partsum(vector<int>& nums,int mask, int k, int sum = 0){
        if (k == 1) return dp[mask] = true;
        if(sum == ksum) return dp[mask] = partsum(nums,mask,k-1,0);
        if (sum > ksum ) return dp[mask] = false;
        if (dp[mask] != -1) return dp[mask];
        for (int i=0; i<N; i++){
            if ((mask & (1<<i)) == 0){
                if (partsum(nums, mask | (1<<i) ,k, sum + nums[i])) return dp[mask] = true;
            }
        }
        return dp[mask] = false;
    }
};