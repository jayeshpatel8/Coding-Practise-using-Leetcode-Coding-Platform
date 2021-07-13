
class Solution {
public:
/*
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int N = strs.size(), dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for (int i=N-1; i>=0; i--){              
            int z = 0, o = 0;
            for (auto c : strs[i]) if (c =='0') z++; else o++;               
            for (int j=m; j>=z; j--)
                for (int k =n; k>=o; k--)
                    if (z<=j && o<=k)
                        dp[j][k] = max(dp[j][k], 1+ dp[j-z][k-o]);
        }
        
        return dp[m][n];
    }
*/
    int memo[601][101][101], N;
    int zo[600][2];
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        N = strs.size();
        
        memset(memo[0],-1,sizeof(memo[0])*(N+1));
        memset(zo[N],0,sizeof(zo[N]));
        for (int i =0 ; i<N; i++) for (auto &c : strs[i]) zo[i][c - '0']++;
        return subseq(strs, 0,n,m);
    }
    int subseq(vector<string>& strs, int i , int ones ,int zeroes){                
        if (i== N) return  0;       
        
        if (memo[i][ones][zeroes] != -1) return memo[i][ones][zeroes];
        
        int ans = subseq(strs,i+1,ones,zeroes);
        if (ones-zo[i][1] >= 0 && zeroes-zo[i][0] >=0){
            ans = max(ans, 1 + subseq(strs,i+1,ones-zo[i][1],zeroes-zo[i][0]));
        }
        return memo[i][ones][zeroes] = ans;
    }
};

