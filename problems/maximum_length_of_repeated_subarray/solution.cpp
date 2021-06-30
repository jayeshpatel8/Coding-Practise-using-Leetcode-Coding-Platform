class Solution {
public:
    int dp[1001][1001];
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int ans=0;
        for (int i = nums1.size()-1; i>=0; i--){
            for (int j=nums2.size()-1; j>=0; j--){
                if (nums1[i] == nums2[j]) dp[i][j] = 1 + dp[i+1][j+1];
                ans  = max(ans,dp[i][j]);
            }
            
        }
        return ans;
    }
};

/*
i , j 
if ([i]==[j]) = 1 + dp[i-1][j-1]
else
 = max(dp[i-1][j],dp[i][j-1])

*/