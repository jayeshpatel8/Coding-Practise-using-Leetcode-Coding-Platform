class Solution {
public:
    int numDistinct(string s, string t) {
        int sl =s.size(), tl=t.size();
        
         vector<uint32_t>  dp(tl+1);
        dp[0]=1;
        for (int i=1; i<=sl; i++)
            for (int j=tl; j>0; j--){
                if (s[i-1]==t[j-1])dp[j] +=dp[j-1];                          
            }
        return dp[tl];;
    }
};