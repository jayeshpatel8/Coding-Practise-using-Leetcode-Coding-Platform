class Solution {
public:
    int numTilings(int n) {
        //vector<int> dp(n+1);
        int mod = 1e9 +7;
        long a=0,b=1,c=1,d=1;
        
        for (int i=2; i<=n; i++){
            // put dom
            //dp[i] =( dp[i] + dp[i-1] + dp[i-2])%mod;             
//               d = (c + b ) %mod;
            //put trom
            /*
            for (int j= i ,k = i-3; j>2; j--)
                dp[i] =( dp[i] + (long)dp[k--]*2)%mod;
            */
            //if (i>=3) 
            {
            //    psum =(psum  + dp[i-3]);// %mod;
            //    dp[i] = (dp[i] + psum * 2) %mod;
//                d = (d + a * 2) %mod;
            }
            // put dom + trom together 
            d = (c + b + a * 2) %mod;
            a+=b;b=c;c=d;
        }
        return d;//dp[n];
    }
    int numTilings3(int n) {
        //vector<int> dp(n+1);
        int mod = 1e9 +7;
        long a=0,b=1,c=1,d=1;
        
        for (int i=2; i<=n; i++){
            // put dom
            //dp[i] =( dp[i] + dp[i-1] + dp[i-2])%mod;             
               d = (c + b) %mod;
            //put trom
            /*
            for (int j= i ,k = i-3; j>2; j--)
                dp[i] =( dp[i] + (long)dp[k--]*2)%mod;
            */
            //if (i>=3) 
            {
            //    psum =(psum  + dp[i-3]);// %mod;
            //    dp[i] = (dp[i] + psum * 2) %mod;
                d = (d + a * 2) %mod;
            }
            
            a+=b;b=c;c=d;
        }
        return d;//dp[n];
    }
    int numTilings2(int n) {
        vector<int> dp(n+1);
        int mod = 1e9 +7;
        dp[0]=dp[1]=1;
        long psum=0;
        for (int i=2; i<=n; i++){
            // put dom
            dp[i] =( dp[i] + dp[i-1] + dp[i-2])%mod;             
            //put trom
            /*
            for (int j= i ,k = i-3; j>2; j--)
                dp[i] =( dp[i] + (long)dp[k--]*2)%mod;
            */
            if (i>=3) {
                psum =(psum  + dp[i-3]);// %mod;
                dp[i] = (dp[i] + psum * 2) %mod;
            }
        }
        return dp[n];
    }
};