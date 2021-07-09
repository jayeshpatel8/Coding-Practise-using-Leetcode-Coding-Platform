class Solution {
public:
    int  N , M;
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
          N = nums1.size(), M = nums2.size();
        //vector<vector<int>> dp(N+1,vector<int>(M+1, INT_MIN));
       int dp[N+1];
        dp[N-1]=nums1[N-1]*nums2[M-1];
        for(int i=N-2;i>=0;i--)  dp[i]=max(nums1[i]*nums2[M-1],dp[i+1]);
        for (int j=M-2; j>=0; j--){
            int prev = dp[N-1];;
            dp[N-1]= max ({prev,nums1[N-1]*nums2[j]});
            for (int i=N-2; i>=0; i--){
                int temp = dp[i];
                
                dp[i] = max({dp[i+1],dp[i],nums1[i]*nums2[j]+ max (0,prev)});
                prev=temp;
            }
        }
        return dp[0];
    }
};