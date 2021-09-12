class Solution {
public:
    int maxProduct(string s) {
        int dp[4096], N = s.size(), ans = 0, MAX = (1<<N)-1;
        dp[0]=0;
        for ( int i=1; i<MAX; i++){
            dp[i] = isPal(s,i);            
        }
        for (int m1=MAX; m1>0; m1--){
            int m2 = m1 ^ MAX;
            if (dp[m1] * (N - dp[m1]) > ans ){
                for (int m3 = m2; m3>0; m3 = (m3-1)& m2 ){
                    ans = max(ans, dp[m1] * dp[m3]);
                }
            }
        }
        return ans;
    }
    int isPal(string & s, int mask){
        int i = 0, j = s.size(), len = 0;
        while ( i<= j){
            if ( (mask & (1<<i)) == 0) i++;
            else if ( (mask & (1<<j)) == 0) j--;
            else if ( s[i] != s[j]) return len;
            else{
                len +=  1 + (i != j); i++;j--;
            }
        }
        return len;
    }
};