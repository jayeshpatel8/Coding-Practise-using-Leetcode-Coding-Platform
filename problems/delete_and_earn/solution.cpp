class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int freq[10001]={}, dp[10001]={};
        for(auto i : nums) freq[i]+=i;        
        dp[0] = freq[0], dp[1] =max(dp[0],freq[1]);
        for (int i=2; i<10001;i++)
            dp[i] = max(dp[i-1], dp[i-2] + freq[i]);
        return dp[1000];
    }
};