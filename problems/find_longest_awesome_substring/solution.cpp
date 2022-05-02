class Solution {
public:
    int longestAwesome(string s) {
        int n= s.size();
        vector<int> dp(1024,n);
        int ans = 0 ;
        dp[0]=-1;
        for (int i=0, mask  =0; i<n; i++){
            auto c  = s[i] - '0';
            mask ^= 1<< c;
            
            if (mask != 0 && dp[mask] == n)
                dp[mask] = i;
            ans = max(ans, i-dp[mask]);
            for (int d=0; d<10; d++){
                ans = max(ans, i-dp[mask ^ (1<<d)]);
            }
        }
        return ans;
    }
};