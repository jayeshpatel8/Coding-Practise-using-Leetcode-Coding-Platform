class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[n], cnt[n];
        if (n==1) return 1;
        dp[n-1]=1;cnt[n-1]=1;
        int mlen=0;
        for (int i=n-2;i>=0; i--){
            dp[i]=1;cnt[i]=1;
            for (int j=i+1; j<n; j++){
                if (nums[i] < nums[j] ){
                    if (dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if (dp[i] == dp[j]+1){
                        cnt[i] +=cnt[j];
                    }
                    
                }
            }
            mlen = max(mlen,dp[i]);
        }
        int ans=0;
        for (int i=0; i<n; i++) if (dp[i]==mlen) ans += cnt[i];
        return ans;
    }
};

/*
 if ()
*/