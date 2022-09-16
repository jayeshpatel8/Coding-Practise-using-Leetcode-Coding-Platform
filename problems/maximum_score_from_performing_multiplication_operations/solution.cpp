class Solution {
public:
    int N, M;
    vector<vector<int>> dp;
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
         N = nums.size();
        M = multipliers.size();
        vector<int> dp2(M+1);

        for (int i=M-1; i>=0; i--){
            int next = dp2[i+1];
            for (int left=i; left >=0; left--){
                auto d = max(nums[left] * multipliers[i] + dp2[left+1],
                                 nums[N- 1 - (i - left)] * multipliers[i] + dp2[left]);
                dp2[left+1]=next;
                next = d;
            }
            dp2[0]=next;
        }
        return dp2[0];
    }
    int maximumScore1(vector<int>& nums, vector<int>& multipliers) {
         N = nums.size();
        M = multipliers.size();
        dp.resize(M+1, vector<int>(M+1,0));

        for (int i=M-1; i>=0; i--){
            for (int left=i; left >=0; left--){
                dp[i][left] = max(nums[left] * multipliers[i] + dp[i+1][left+1],
                                 nums[N- 1 - (i - left)] * multipliers[i] + dp[i+1][left]);
            }
        }
        return dp[0][0];
    }
    int maximumScore2(vector<int>& nums, vector<int>& multipliers) {
         N = nums.size();
        M = multipliers.size();
        dp.resize(M, vector<int>(M,INT_MIN));
        return dfs(nums, multipliers, 0, 0);
    }    
    int dfs(vector<int>& nums, vector<int>& multipliers, int i, int left) {
        if (i == M) return 0;
        if (dp[i][left] != INT_MIN) return dp[i][left];
        int ans, right = N - 1 - (i - left);
        ans = nums[left] * multipliers[i] + dfs(nums,multipliers,i+1,left+1);
        ans= max(ans, (nums[right] * multipliers[i]) + dfs(nums,multipliers,i+1,left));
        return dp[i][left] =ans;
    }
};