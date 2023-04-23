class Solution {
public:
    int numberOfArrays(string s, int k) {
        int N =  s.size(), mod = 1e9 +7;
        vector<int> dp(N+1);
        for (int i=0; i<N; i++){
            long sum = 0;
            dp[0]=1;
            if (s[i] == '0' || dp[i]==0) continue;
            for (int j=i ; j<N; j++){
                sum =  sum * 10 + s[j]-'0';
                if (sum > k) break;
                dp[j+1] =(dp[j+1] + dp[i])%mod;
                
            }
        }
        return dp[N];
    }
};