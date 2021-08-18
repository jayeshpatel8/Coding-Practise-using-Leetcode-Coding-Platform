class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(128);
        int len=1;
        dp[p[0]]=1;
        for (int i=1; i<p.size(); i++){
            if (p[i] == p[i-1] + 1 || (p[i]=='a' && p[i-1]=='z'))
                len++;
            else 
                len=1;
            dp[p[i]] = max(dp[p[i]],len);
        }
        
        return accumulate(begin(dp) + 'a' , begin(dp)+'z'+1,0);
    }
};