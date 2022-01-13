class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> valid(1<<n ,-1);
        
        for (int mask =0; mask < (1<<n); mask++){
            if (__builtin_popcount(mask) == n/k){
                bool v=true;
                int freq[17]={}, mi=INT_MAX,ma=INT_MIN;
                
                for (int idx=0; idx<n; idx++){
                    if ((mask & (1<<idx)) == 0) continue;
                    if (freq[nums[idx]]++ > 0){
                        v=false; 
                        break;
                    }
                    mi = min(mi, nums[idx]);
                    ma = max(ma, nums[idx]);
                }
                if (v){
                    valid[mask] = ma-mi;
                }
            }
        }
        
        vector<int> dp(1<<n ,-1);
        dp[0]=0;
        for (int mask=1; mask < (1<<n); mask++){
            if (__builtin_popcount(mask) % (n/k) == 0){
                for (int smask=mask ; smask; smask  = (smask-1) & mask){
                    if (valid[smask] != -1 && dp[smask ^ mask]!= -1){
                        if (dp[mask] == -1)
                            dp[mask] = valid[smask] + dp[ smask ^ mask];
                        else
                            dp[mask] = min(dp[mask], valid[smask] + dp[smask ^ mask]);
                    }
                }
            }
        }
        return dp[(1<<n)-1];
    }
};