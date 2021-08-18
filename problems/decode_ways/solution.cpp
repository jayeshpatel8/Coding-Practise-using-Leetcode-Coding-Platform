class Solution {
public:
    int numDecodings(string s) {
        int  N = s.size();
        int dp[N][2];
        dp[0][0] = s[0] != '0'; dp[0][1]=0;
        
        for(int i=1; i<N; i++){
            dp[i][0]=dp[i][1]=0;
            if(s[i] != '0')    
                dp[i][0] = dp[i-1][0] + dp[i-1][1];
            if (s[i-1] == '1' || ( s[i-1] == '2' && s[i]<='6' ))
                dp[i][1] = dp[i-1][0];
        }
        return dp[N-1][0] + dp[N-1][1];
    }
};