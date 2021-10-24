class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int N = nums.size(), dp[1<<N], max_or = 0, ans=0;
        dp[0]=0;
        
        for (auto i : nums) max_or |=i;
        
        for (int i=1; i<(1<<N); i++){
            int lsb = i & -i;
            dp[i] = dp[i - lsb] | nums[__builtin_ctz(lsb)];
            if (dp[i] == max_or) ans++;
        }
        return ans;
    }
};