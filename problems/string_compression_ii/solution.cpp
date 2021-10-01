class Solution {
public:
    
    int getLengthOfOptimalCompression(string s, int k) {
        int N = s.size(), dp[N+1][N+1];

        
        for (int i=N;i>=0; i--){
            for (int j=0; j<=k; j++){
               if (i == N) {dp[N][j] = 0; continue;}
                // either delete the ith character (if j > 0)
                dp[i][j] = j > 0 ? dp[i+1][j-1] : INT_MAX;
                {/*
                    int freq[26]={};
                    for ( int m = i, most = 0; m<N; m++){
                        most =max (most, ++freq[s[m]-'a']);
                        if (j - (m-i+1-most) >= 0)
                            dp[i][j] = min (dp[i][j] ,  1 + len(most) + dp[m+1][j - (m-i+1-most)]);
                    }    */
                    int K = j, cnt = 0;
                    for (int m = i; m < N && K >= 0; m++) {
                        if (s[m] == s[i]) {
                            cnt++;
                            // assuming the block ends here
                            dp[i][j] = min(dp[i][j], 1 + len(cnt) + dp[m+1][K]);
                        } else {
                            // this character would be deleted
                            K--;
                        }
                    }                    
                }
            }
        }
        return dp[0][k];
    }
    
    int N, dp[101][101];
    
    int getLengthOfOptimalCompression2(string s, int k) {
        N = s.size();
        memset(dp,-1,sizeof(dp));
        return dfs(s,0,k);
    }
    int dfs(string & s, int i, int k){
        if(k<0) return 1000;
        if( i>=N || N-i<=k) return 0; // delete remaining char if k >= 0
        if (dp[i][k] != -1)return dp[i][k];
        /*
        int freq[26]={}, ans = INT_MAX;
        for ( int j = i, most = 0; j<N; j++){
            most =max (most, ++freq[s[j]-'a']);
            ans = min (ans ,  1 + len(most) + dfs(s,j+1, k - (j-i+1-most)));
        }*/
        int ans = dfs(s,i+1,k-1);
        int K = k, cnt = 0;
        for (int m = i; m < N && K >= 0; m++) {
            if (s[m] == s[i]) {
                cnt++;
                // assuming the block ends here
                ans = min(ans, 1 + len(cnt) + dfs(s,m+1,K));
            } else {
                // this character would be deleted
                K--;
            }
        } 
        return dp[i][k] = ans;
    }
    int len2(int n){
        return n==0? 0 : 1 +  (n==1 ? 0 : n<10 ? 1 : n<100 ? 2:3);
    }
    int len(int n){
        return n==1 ? 0 : n<10 ? 1 : n<100 ? 2:3;
    }                               
    
};