class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int dp[1002][1002]={},ans=0;
        
        for ( int i=1; i<=nums1.size(); i++){
            for (int j=1; j<= nums2.size(); j++){
                if (nums1[i-1] == nums2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
               // else
                   // dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                ans= max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};