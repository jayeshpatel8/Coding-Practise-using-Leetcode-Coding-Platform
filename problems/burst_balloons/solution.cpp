class Solution {
public:
    int dp[501][501];
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return mCoin(0,nums.size()-1,nums);
    }
    int mCoin(int i, int j, vector<int>& nums){
        if (i>j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int coins=0;
        for (int k = i; k<=j; k++){
            coins = max(coins, mCoin(i,k-1,nums) + mCoin(k+1,j,nums) + (i==0? 1 : nums[i-1]) * nums[k] * (j+1==nums.size()? 1 : nums[j+1]));
        }
        return dp[i][j] = coins;
    }
};