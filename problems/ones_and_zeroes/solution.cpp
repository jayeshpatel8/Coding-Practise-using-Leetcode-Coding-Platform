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
    /*
        int dp[601][101][101], M,N;
        vector<array<int,2>> cnt;
    int findMaxForm2(vector<string>& strs, int m, int n) {
        M=m; N=n;
        memset(dp,-1,sizeof(dp));
        
        for (auto &s  : strs){
            int c0=0,c1=0;    
            for (auto &c : s) 
                if (c=='0')c0++;
                else c1++;            
            cnt.push_back({c0,c1});
        }
        //sort(begin(strs),end(strs),[](auto &a, auto &b){ return a.size() < b.size();})
        return dfs(strs,0,m,n);
        
    }
    int dfs(vector<string>& strs, int i, int m, int n) {
        if (i >= strs.size() || (m == 0 && n == 0) ) return 0;
        if (-1 != dp[i][m][n]) return dp[i][m][n];
        int ans = 0;
        if (cnt[i][0] <=m && cnt[i][1] <=n){
            ans = 1 + dfs(strs,i+1,m-cnt[i][0] , n - cnt[i][1]);
        }
        ans = max(ans, dfs(strs,i+1,m , n ));
        return dp[i][m][n] = ans;
    }
    */
};