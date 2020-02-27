class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len<2) return 0;
        int dp[len]={0};
        int m=0;
        for (int i=1; i<len; i++){
            if (s[i] == ')' )
                if (s[i-1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) +2;                                   
                else if (((i-dp[i-1]-1)>=0 && (s[(i-dp[i-1]-1)] == '(')))
                    dp[i]=dp[i-1]+(((i-dp[i-1]-2)>0)?dp[i-dp[i-1]-2]:0)+2;
                m = max(dp[i],m);
          //  cout << dp[i] << ",";
        }    
        //cout << endl;
        return m;
    }
};