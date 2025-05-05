class Solution {
public:
    int numTilings(int n) {
        int mod = 1e9 +7;
        long a=0,b=1,c=1,d=1;
        
        for (int i=2; i<=n; i++){
            // put dom

            d = (c + b + a * 2) %mod;
            a+=b;b=c;c=d;
        }
        return d;//dp[n];
    }
};
