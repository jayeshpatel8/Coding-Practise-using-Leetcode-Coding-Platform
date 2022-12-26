class Solution {
public:
    int dp[1001][1001] ={}, N , K, mod=1e9+7;
    using ll = long long;
    int countPartitions(vector<int>& nums, int k) {
        N = nums.size(), K = k;
        ll total = 1 ,sum = 0;
        for (auto i : nums) sum +=  i;
        if (sum < 2 * k) return 0;
        for (int i=0; i<N; i++) total = (total *2LL)%mod;
        return (mod - 2* dfs(nums,0,0) + total-2)%mod;
    }
    int dfs(vector<int>& nums, int i, int sum ){
        if (sum >=K || i==N) return sum<K && sum>0;
        if (dp[i][sum] == 0){
            dp[i][sum] = (1 + dfs(nums,i+1,nums[i]+sum) + dfs(nums,i+1,sum))%mod;
        }
        return dp[i][sum] - 1;
    }
};