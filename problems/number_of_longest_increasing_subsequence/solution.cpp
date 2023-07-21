class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1) ,cnt(nums.size(),1);
        for (int i = 0; i <nums.size(); i++){
            
            for (int j=i-1; j>=0; j--){
                if (nums[j] >= nums[i]) continue;
                if (dp[j] +1 > dp[i]){
                    dp[i]=dp[j] +1;
                    cnt[i]=cnt[j];
                }
                else if(dp[j] +1 == dp[i])
                    cnt[i]+=cnt[j];
            }
        }
        int longest = *max_element(begin(dp),end(dp)), ans = 0;
        for (auto i=0; i<nums.size(); i++){
            if (dp[i] == longest) ans += cnt[i];
        }
        return ans;
    }
};