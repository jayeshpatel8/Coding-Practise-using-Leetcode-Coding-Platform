class Solution {
public:
    double new21Game(int n, int k, int W) {
        if (k==0 || n>= k-1+W) return 1;
        
        double dp[n+1], sum = 1.0,ans=0.0;
        dp[0]=1.0;
        
        for (int i=1; i<=n; i++){
            dp[i]=sum/W;
            if (i<k) sum +=dp[i];             
            if (i+1-W >= 1) sum-=dp[i-W];            
        }
        for (int i=k; i<=n; i++) ans +=dp[i];
        return ans;
    }
};
