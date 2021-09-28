class Solution {
public:
    string longestPrefix(string s) {
        int N = s.size();
        vector<int> dp(N);
        int i =1,j=0;
        for ( ; i <N; i++){
            while(j > 0 && s[i] != s[j]) j = dp[j-1];
            if(s[i] == s[j])
                dp[i] = ++j;
        }
        return s.substr(0,dp[N-1]);
    }
};