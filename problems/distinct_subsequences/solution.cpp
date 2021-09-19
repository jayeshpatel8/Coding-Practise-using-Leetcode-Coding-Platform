class Solution {
public:
        int numDistinct(string s, string t) {
        int N = s.size();
        vector<size_t> dp(t.size()+1);
        dp[0]=1;
        for ( int i=1; i<= N; i++){
            for(int j=t.size(); j>0; j--){                
                if (s[i-1]==t[j-1])
                    dp[j] +=dp[j-1]; // all previously matched so far for t[j-1] + exapanding one
            }
        }
        return dp[t.size()];
    }
/*    
    int numDistinct(string s, string t) {
        int N = s.size();
        vector<vector<size_t>> dp(t.size()+1,vector<size_t>(N+1));
        for (int i=0; i<=N; i++) dp[0][i]=1;
        for(int j=1; j<=t.size(); j++){
            for ( int i=1; i<= N; i++){
                dp[j][i] = dp[j][i-1]; // all previously matched so far for t[j-1]
                if (s[i-1]==t[j-1])
                    dp[j][i] +=dp[j-1][i-1];
                
            }
        }
        return dp[t.size()][s.size()];
    }*/
    /* TLE 
    int dp[1001][1001];
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        
        return dfs(s,t,0,0);
    }
    int dfs(string& s, string& t, int i, int j){
        if (i>s.size())
            return 0;
        if (j == t.size()) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        
        for (; i<s.size(); i++){
            if (s[i]==t[j])
                ans += dfs(s,t,i+1,j+1);
        }
        return dp[i][j]= ans;        
    }
    */
};