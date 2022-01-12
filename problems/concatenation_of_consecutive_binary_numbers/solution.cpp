class Solution {
public:
    int  mod = 1e9 + 7;  
    int dp[1 << 20]={};
    int concatenatedBinary(int n) {
        
        for ( int i=0; i<0; i++){
            unsigned long long ans = 1;
            if (n>63){
                if (n%2) ans = 2, n--;
                 ans = (ans * dp[n/2] * dp[n/2]) %mod;
            }
            else
                ans = (1UL<<n)%mod;
            dp[i]= ans;
        }
        unsigned long long ans =0;        
        unsigned long long cnt =0, mul=1;
        while(n>0){
             ans =  (ans + (n * mul)%mod )%mod ;
            mul = (mul * multip(getmsbpos(n--)))%mod;
            //if (mul > 60) mul = 60;
            
            
        }
        return ans % mod;
    }
    int getmsbpos(int n){
        int p=19;
        while (p>0){
            if ((1<<p) & n) return ++p;
            p--;
        }
        return 1;
    }
    unsigned long long multip( int m){
        unsigned long long ans = 1;
        if (dp[m]) return dp[m];
        if (m < 60) 
            return dp[m] = (1ULL << m)%mod;
        
        if (m%2)
            ans = (ans * 2) % mod, m--;
        
        return dp[m] = ( ans * (multip(m/2) * multip(m/2))%mod)%mod;

    }
};