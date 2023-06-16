class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        long long ans = LONG_MAX;
        int  n = nums.size();
        vector<long long> dp(n);
        
        for (long i=0; i <n; i++){
             dp[i]+=i*x;
             int cur = nums[i];
            for (auto shift=0; shift<n; shift++){
                cur = min(cur, nums[(i-shift+n)%n]);
                dp[shift]+=cur;
            }
        }
        for (auto i : dp) ans = min(ans, i);
        return ans;
    }
};