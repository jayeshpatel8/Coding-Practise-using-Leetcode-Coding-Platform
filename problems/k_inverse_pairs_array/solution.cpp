class Solution {
public:
    int dp[1001][1001];
    int N;
    int kInversePairs(int n, int k) {

        //N = n;
        //memset(dp,0,sizeof(dp));
        
        for (int i=0; i<=n; i++){
            dp[i][0]=1;
            for (int j=1; j<=k; j++){
                //if (j==0) dp[i][0]=1;
                //else
                {
                    long sum =0, end = min(j,i-1);
                    for (int k1=0; k1<=end; k1++){
                        sum= (sum + dp[i-1][j-k1]);// % ((int)1e9 + 7 ) ;
                    }
                    dp[i][j] = (sum ) % ((int)1e9 + 7 ) ;
                }
            }
        }
        return dp[n][k];                                
        //return kInv(n,k);
    }
    int kInv(int n, int k){
        if (n==0) return 0;
        if (k==0) return 1;
        if (dp[n][k] ) return dp[n][k];
        int sum =0;
        for (int i=0; i<=min(k,n-1); i++){
            sum= (sum + kInv(n-1,k-i)) % ((int)1e9 + 7 ) ;
        }
        
        return dp[n][k]=sum;
    }
};