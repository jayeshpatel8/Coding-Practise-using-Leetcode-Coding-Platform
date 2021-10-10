class Solution {
public:
    int mod = 1e9 + 7;
    int dp[2002][2002]={};
    int numberOfSets(int n, int k) {
     /* n =8 ,11111111 for k=1, no aditional zero needed
                   for k=2, 11 0 11 , (k-1) zero needed  1111 0 1111 
                   for k=3, 11 0 11 , (k-1) zero needed  1111 0 11 0 11 
        so  (k-1) additional zero needed
        total => n + k - 1 points choose 2k points
       */                
        
        return nCk(n + k - 1, 2 * k);
    }
    int nCk(int n , int m){
        return (n==0 || m==0 || n== m) ? 1 :
                                        dp[n][m] ? dp[n][m] :
                                                            dp[n][m]=(nCk(n-1,m) + nCk(n-1, m-1))%mod;
    }
};