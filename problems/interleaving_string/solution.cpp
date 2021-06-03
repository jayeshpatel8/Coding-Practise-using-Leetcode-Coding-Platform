class Solution {

public:
        int dp[101];
    int m, n, N;
    bool isInterleave(string s1, string s2, string s3) {
                
        m = s1.length();
        n = s2.length();
        N = s3.length();
        if (m+n != N) return false;
        
        for (int i=0; i<=m; i++){
            for (int j=0; j<=n; j++){
                if (i==0 &&  j==0) dp[0]=1;
                else if(i==0){
                    dp[j]= dp[j-1] && s2[j-1] ==s3[i+j-1];
                } else if(j==0){
                    dp[j]= dp[j] && s1[i-1] ==s3[i+j-1];
                }else{
                    dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        
        return dp[n];
    }

};