class Solution {
public:
    int nthUglyNumber(int n) {
     
        int i=0,j=0,k=0;
        int dp[n];
        dp[0]=1;
        for ( int m=1;m<n; m++)
        {
            int n1 = dp[i]*2,  n2 = dp[j]*3, n3 = dp[k]*5;
            dp[m] = min({n1,n2,n3});
            if (n1 == dp[m]) i++;
            if (n2 == dp[m]) j++;
            if (n3 == dp[m]) k++;
            
        }
        return dp[n-1];
    }
};