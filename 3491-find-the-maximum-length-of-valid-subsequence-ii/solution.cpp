class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int res = 0;
        for (int num : nums) {
            auto a = num % k;
            for (int b = 0; b < k; ++b) {
                dp[b][a] = dp[a][b] + 1;
                res = max(res, dp[b][a]);
            }
        }
        return res;
    }
};
