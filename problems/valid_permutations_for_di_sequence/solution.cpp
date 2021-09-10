class Solution {
public:
    int vis[201],mod=1e9 + 7;
    int dp[201][201];
    int numPermsDISequence(string s) {
        int dp[201][201]={}, N = s.size(),mod=1e9 + 7;
        for (int j=0; j<=N; j++) dp[0][j]=1;
        
        for(int i=0; i<N; i++){
            if (s[i]=='I'){
                dp[i+1][0]= dp[i][0];
                for (int j=1; j<N-i; j++)  // prefix sum start from 0 
                    dp[i+1][j]= (dp[i][j] + dp[i+1][j-1])%mod;
            }
            else{
                for (int j=N-1-i; j>=0; j--) // postfix/suffix sum end at 0 
                    dp[i+1][j]= (dp[i][j+1] + dp[i+1][j+1])%mod;                
            }
        }
        return dp[N][0];
    }     
    int numPermsDISequence2(string s){
        memset(dp,-1,sizeof(dp));
        memset(vis,0,sizeof(vis));
        int ans = 0;
        for(int i=0; i<=s.size(); i++)
            if(vis[i] == 0){   
                vis[i] = 1;
                ans = (ans + dfs(s,0,i))%mod;
                vis[i] = 0;
            }

        return ans;
    }
    int dfs(string& s,int i, int n){
        if (i>=s.size()) return 1;
        if(dp[i][n] != -1) return dp[i][n];
        int ans = 0;
        if (s[i]=='D'){
            for(int j=0; j<n; j++){
                if(vis[j] == 0){   
                    vis[j] = 1;
                    ans = (ans + dfs(s,i+1,j))%mod;
                    vis[j] = 0;
                }
            }
        }
        else{
            for(int j=n+1; j<=s.size(); j++)
                if(vis[j] == 0){   
                    vis[j] = 1;
                    ans = (ans + dfs(s,i+1,j))%mod;
                    vis[j] = 0;
                }
        }
        return dp[i][n] = ans;
    }
 
};