class Solution {
public:
    int peopleAwareOfSecret(int n, int de, int fo) {
        
        int dp[1001]={} , mod= 1e9 + 7;
        int ans = 0,spreding=0;
        dp[0]=1;
        for (int i=1; i<n; i++){            
                (spreding += dp[i])%=mod;
                if (i-de>=0)
                    (spreding += dp[i-de])%=mod;
                if (i-fo >=0)
                    spreding = (spreding - dp[i-fo] + mod) %mod;
            
            dp[i]=spreding;
    
        }

    for (int i=n-fo; i<n; i++)
                if (i >=0)
                    ans = (ans + dp[i]) % mod;

        return ans %mod;
    }
};
