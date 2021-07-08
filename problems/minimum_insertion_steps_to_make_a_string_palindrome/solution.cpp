class Solution {
public:
    int dp[501][501];
    int minInsertions(string s) {
        for (int len=1; len<s.size();len++){
            for (int i=0,j=len; i<s.size()-len; i++,j++){
                
                if (s[i] == s[j] ){
                    if (i+1<j )dp[i][j] = ( dp[i+1][j-1]);
                }
                else dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.size()-1];
    }
    /*
    int mi(string &s, int i, int j){
        if (i>=j) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        
        dp[i][j] = 1 + min(mi(s,i,j-1), mi(s,i+1,j));
        if (s[i] == s[j]) dp[i][j] = min(dp[i][j], mi(s,i+1,j-1));
        return dp[i][j];
    }
    */
};