class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> z(n+2),dp(n+2);
        //z[0] = nums[0]==0;
        for (int i=0; i<n; i++){
            z[i+1] = z[i] + (nums[i]==0);
            
        }
        int ones=0, a= 0;
        a = max(a, z[n]);
        dp[n] = a;
        for (int i=n-1; i>=0; i--){
            ones += nums[i];
            
            dp[i] = ones + (z[i] );
            a = max(a, dp[i]);
        }
        a = max(a, ones);
        dp[0]=ones;

        vector<int> ans;

        for (int i=0; i<=n; i++)
            if (dp[i] == a)
                ans.push_back(i);
        
        return ans;
    }
};