class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int  N = nums.size();
        int f[101]={};
        vector<int> dp(N);
        for ( int i=0; i<N; i++){
            for ( int j = i-1; j>=0; j--){
                if (nums[j]  > nums[i])
                    dp[j]++;
                else if (nums[j] < nums[i])
                    dp[i]++;
            }
        }
        return dp;
    }
};