class Solution {
public:
    int dp[1001];
    bool divisorGame(int n) {
        memset(dp,-1,sizeof(dp));
        return (n&1) == 0;
        return play(n);
    }
    bool play(int n){
        if(n<=1) return false;
        if(dp[n] != -1) return dp[n];
        bool ans=false;
        for (int x = 1; x<n; x++){
             if (n%x) continue;
            ans |= !play(n-x);
        }
        return dp[n]= ans;
    }
};