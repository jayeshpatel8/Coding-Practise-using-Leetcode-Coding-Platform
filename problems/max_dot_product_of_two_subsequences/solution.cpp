class Solution {
public:
    int  N , M;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
          N = nums1.size(), M = nums2.size();
        //vector<vector<int>> dp(N+1,vector<int>(M+1, INT_MIN));
       int dp[N+1][M+1];
        
        for (int i=N; i>=0; i--){
            for (int j=M; j>=0; j--){
                if (i==N||j ==M) dp[i][j]=INT_MIN;
                else
                    dp[i][j] = max({dp[i+1][j],dp[i][j+1],nums1[i]*nums2[j]+ max (0,dp[i+1][j+1])});     
            }
        }
        return dp[0][0];
    }
};