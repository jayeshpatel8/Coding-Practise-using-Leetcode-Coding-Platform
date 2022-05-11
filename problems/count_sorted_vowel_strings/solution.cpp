class Solution {
public:
    int countVowelStrings(int n) {
        
        int dp[5]={1,1,1,1,1};
        
        while (n-- > 1){
           // dp[0] = dp[0] ; // ending at a
            dp[1] += dp[0]  ; //ending at e
            dp[2] += dp[1] ; //ending at i
            dp[3] += dp[2] ; //ending at o
            dp[4] += dp[3] ; //ending at u            
            
        }
        
        return accumulate(begin(dp),end(dp),0);
    }
    /*
    int dp[51][5];
    string s = "aeiou";
    int countVowelStrings2(int n) {
        
        memset(dp,-1,sizeof(dp));
        
        return dfs(n,0);
    }
    int dfs(int n, int i){
        if (n == 0) return 1;
        if (i>=5) return 0;
        if (dp[n][i] != -1) return dp[n][i];
        int ans = 0;
        for (int j = i; j<5; j++){
             ans += dfs(n-1,j);
        }
        return dp[n][i] = ans;
    }
    */
};