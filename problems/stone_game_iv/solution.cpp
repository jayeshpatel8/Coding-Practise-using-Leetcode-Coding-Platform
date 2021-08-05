class Solution {
public:
    int dp[100001];
    bool winnerSquareGame(int n) {
        dp[0]=0;
        for (int i=1; i<=n; i++){
            bool ans=false;
            for (int j=1 ; !ans && j*j<=i; ++j){
                ans |= !dp[i - j*j];
            }  
            dp[i]=ans;
        }
        return dp[n];
    }
    /*
    
    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(int)*(n+1));
        return dfs(n);
    }
    bool dfs(int n){
        if (n==0) return false;
        if(dp[n]!=-1) return dp[n];
        bool ans =false;
        
        for (int j=1, k = 1 ; !ans &&  j*j<=n; ++j){
            ans = !dfs(n - j*j);
        }
        return dp[n] = ans;
    }
    */
};