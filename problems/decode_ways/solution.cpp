class Solution {
public:
    int N;
    int dp[100];
    int numDecodings(string s) {
        N=s.length();
        for ( int i=0; i<N;i++) dp[i]=-1;
        return numDecodings_(s,0);
    }
    int numDecodings_(string s, int i) {
        if (i>=N) return 1;
        
        if (dp[i]!=-1) return dp[i];
        int sum=0;
        if (s[i]>'0' && s[i]<='9') {
            sum += numDecodings_(s,i+1);
        
            if (s[i]<'3' && (1+i)<N && 
             (   (s[i] == '2' && s[i+1]>='0' && s[i+1]<='6') || 
              (s[i] == '1' && s[i+1]>='0' && s[i+1]<='9'))
            )
                sum +=numDecodings_(s,i+2);
        }
        return dp[i]=sum;
    }
};