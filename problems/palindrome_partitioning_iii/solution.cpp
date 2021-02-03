class Solution {
public:
    int n;
    int dp[101][101]  ={};
    vector<vector<int>> memo ;
    int palindromePartition(string s, int k) {
        
        n = s.size();
        if(k == n) return 0;
#if 0        
        for (int L=0; L<n; L++){
            for (int i=L,j=L,k=L+1; i>=0 && j<n; j++,i--){                
                if (s[i]!=s[j]) 
                    dp[i][j]+=1;

                if (i+1<j-1)
                    dp[i][j] += dp[i+1][j-1];                 
                if (k<n ){
                    if (s[i]!=s[k]) 
                        dp[i][k]+=1;

                    if (i+1<k-1)
                        dp[i][k] += dp[i+1][k-1];
                    k++;
                }
            }
        }   
#endif
        for(int i = 0; i< n-1; i++) dp[i][i+1] = s[i]!=s[i+1];
        for(int L = 2; L< n; L++)
        {            
            for(int j = 0; j+L < n; j++)
            {
                int i = j+L;
                dp[j][i] = dp[j+1][i-1] + (s[i] != s[j]);
            }
        }        
        if(k == 1) return dp[0][n-1];
        memo.resize(n+1,vector<int>(k+1,-1));

        return pal(k,0);
    }
    int pal( int k, int i){
        //if (i>=n || k<1) return 101;
        if (k==1) return  memo[i][k]=dp[i][n-1];
        
        if(memo[i][k]==-1){
            int change=101;
            for (int j=i; j<n && n-j >=k; j++){
                change = min(change, dp[i][j] + pal(k-1,j+1));
            }            
            memo[i][k] = change;
        }
        
        return memo[i][k];
    }
};