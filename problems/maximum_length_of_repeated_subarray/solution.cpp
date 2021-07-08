class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans=0;
        int dp[n+1][m+1];
        memset(dp,0,sizeof (dp));
        
        for (int i=n-1; i>=0; i--){
            for (int j=0; j <m  ; j++){
                if (nums1[i] == nums2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1] ;
                    ans = max(ans, dp[i][j]);
                } 
            }
        }
        return ans;
    }
};