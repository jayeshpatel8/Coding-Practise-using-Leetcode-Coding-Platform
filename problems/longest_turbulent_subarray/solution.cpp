class Solution {
public:

    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n==1) return 1;
        vector<vector<int>> dp(n,vector<int>(2,1));

        int ans = 1;
        for (int i=1; i<n; i++){
            if (arr[i-1]>arr[i]){
                dp[i][0] +=dp[i-1][1];
                ans = max(ans, dp[i][0]);
            }
            else if (arr[i-1] < arr[i]){
                dp[i][1] +=dp[i-1][0];
                ans = max(ans, dp[i][1]);                
            }
            // else 0 , 0
        }
        return ans;
    }
};