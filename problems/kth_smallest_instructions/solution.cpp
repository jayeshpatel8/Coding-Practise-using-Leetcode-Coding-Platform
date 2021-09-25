class Solution {
public:
    string kthSmallestPath(vector<int>& des, int k) {
        
        int r= des[0] , c = des[1], n = r+c;
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        //ncr using pascal traingle
        for ( int i=1; i<=n; i++){
            dp[i][0] = 1;
            for (int j =1; j<=i; j++)
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
        string ans;
        int v=r;
        for ( int i=0,rem = n - (i+1);i<n; i++){            
            if (dp[rem][v] >= k)
                ans +='H';
            else 
                ans +='V',  k-=dp[rem][v--];
            rem--;
        }
        return ans;
    }
};