class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int cnt[26]={};
        
        for (auto c : s)
            cnt[c-'a'] = accumulate(cnt,cnt+26,1UL)%mod;
        
        return accumulate(cnt,cnt+26,0UL)%mod;
    }
    int distinctSubseqII1(string s) {
        int cnt[26]={}, dp[s.size()+1];
        dp[0]=1; 
        for (auto i=1; i<=s.size(); i++){
            // all unique num of len n => 2 ^ n
            // if there is repeate => 2 * prev - cntoflast 
            //  ab|a => {""}, {"", a} , {ab,b} | a => {aba,ba, "a", "aa"}
            // 1 , 2 , 4 , (4 *2) - 2 => 6 == 6
            // aba|b => count of (aba) * 2 - count of[last b]
            dp[i] = (((size_t)dp[i-1] * 2)%mod + mod - cnt[s[i-1]-'a'])%mod;
            cnt[s[i-1]-'a'] = dp[i-1];
        }
        return dp[s.size()]-1;
    }
};