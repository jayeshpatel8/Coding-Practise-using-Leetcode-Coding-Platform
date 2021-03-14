class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        
        vector<unordered_map<int, int>> freq(k);
        int n = nums.size();
        for (int i=0; i<n; i++){
            freq[i%k][nums[i]]++;
        }
        
        vector<vector<int>> dp(k+1,vector<int>(1024,n));
        dp[0][0]=0;
        int prev_i_best=0;
        for (int i=0; i<k; i++){
            
            int cntofi = n/k + (i<n%k?1:0);
            int bestati=n;
            for(int j=0; j<1024; j++){
                
                for(int seg=i; seg<n; seg+=k){
                    dp[i+1][j] = min(dp[i+1][j], dp[i][j ^ nums[seg]] + cntofi - freq[seg%k][nums[seg]]);
                    
                }
                dp[i+1][j] = min(dp[i+1][j], prev_i_best + cntofi);
                bestati = min(bestati,dp[i+1][j] ); 
            }
            prev_i_best = bestati ; 
        }
        return dp[k][0];
    }
};