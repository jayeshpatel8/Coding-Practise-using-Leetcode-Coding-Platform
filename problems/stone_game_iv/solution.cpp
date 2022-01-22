class Solution {
public:
    vector<int> sq;
    bool winnerSquareGame(int n) {
        
        //vector<int> dp(n+1,-1);
        for (int i=1, j =1; j <=n;i++ ){
            sq.push_back(j);
            j = i*i;
        }
        vector<bool> dp(n+1,0);
        for ( int i =1; i<=n; i++){
            bool ans= false;
            for (auto &j : sq){
                if (j > i || ans)break;
                ans = ans | !dp[i-j]; 
            }
            dp[i] = ans;
        }
        return dp[n];
        //return dfs(n,dp);
    }
    bool dfs(int n,vector<int>& dp){
        if (n ==0 ) return false;
        if (dp[n] != -1) return dp[n];
        
        bool ans = false;
        
        for (auto i :sq){
            if (i > n ) break;
            ans |= !dfs(n-i,dp);
            if (ans) break;
        }
        return dp[n] = ans;
    }
};