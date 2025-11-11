class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
         memset(dp,0,sizeof(dp));
        for (auto &s  : strs){
            int c0=0,c1=0;    
            for (auto &c : s) if (c=='0') c0++; else c1++;
            
            for (int i=m; i>=c0; i--){
                for (int j=n; j>=c1; j--){
                    dp[i][j] = max(dp[i][j] , 1 + dp[i-c0][j-c1]);
                }
            }            
        }
        return dp[m][n];
    }
};
