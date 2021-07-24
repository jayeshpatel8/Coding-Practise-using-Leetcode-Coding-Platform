class Solution {
public:

    int racecar(int t) {
        /*
                find j if t == 2^n -1 then ans  = n 
                else [ k = j-1 to k > 0 ] min( 0-j + j-K + k-i )
        */
        static vector<int> dp(1e4 + 1 ,-1);
        if (dp[t] != -1) return dp[t];
        int i = floor(log2(t)) + 1;
        dp[t] = 1e8;
        if ( t == (1<<i)-1 ) return  dp[t] = i;
         // 0x100 - 1 = 0x11
                
        for (int m = 1, upper = 1;  upper<t;  upper= (1<<++m)-1){
            for ( int  n=0,  lower=0;   lower<upper;    lower=(1<<++n)-1)
            {
                dp[t] = min(dp[t], m + 1 + n + 1 + racecar(t - (upper - lower) ));
            }
        }
        dp[t] = min(dp[t],i +  1 + racecar( (1<<i)-1  -t) );
        
        return dp[t];
        
    }
};