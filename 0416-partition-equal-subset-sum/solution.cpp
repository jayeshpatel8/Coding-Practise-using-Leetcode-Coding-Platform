class Solution {
public:   
    bool canPartition(vector<int>& nums) {
        int sum  = 0;
        
        for (auto i : nums) sum += i ;
        if (sum%2) return false;
        
        vector<bool> dp(sum/2+1);
        dp[0]=1;
        for (auto i : nums){
            for (int s = sum/2 - i; s>=0; s--){
                if (dp[s])
                    dp[s+i] = true;
            }
        }
        return dp[sum/2];
    }
};
