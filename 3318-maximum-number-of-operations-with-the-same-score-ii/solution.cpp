class Solution {
public:
    vector<vector<int>> dp;
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        
        dp.resize(n, vector<int>(n, -1));
        int j= nums.size()-1,ans=0;
        ans = cnt(nums, 0,nums.size()-1, nums[0] +nums[1]);
        dp.assign(n, vector<int>(n, -1));
        ans = max(ans, cnt(nums, 0,j, nums[0] +nums[j]));
        dp.assign(n, vector<int>(n, -1));
        ans = max(ans, cnt(nums, 0,j, nums[j-1] +nums[j]));
        return ans;
    }
    int cnt(vector<int>& nums, int i, int j, int sum) {
        if (j<=i) return 0;
        if (dp[i][j]>=0) return dp[i][j];
        int ans = 0;
        {
            if ( nums[i] + nums[i+1] == sum) ans = 1 + cnt(nums, i+2,j,sum);
            if ( nums[j] + nums[j-1] == sum) ans = max(ans, 1 + cnt(nums, i,j-2,sum));
            if ( nums[j] + nums[i] == sum) ans = max(ans, 1 + cnt(nums, i+1,j-1,sum));
        }
        return dp[i][j] = ans;
    }
};
