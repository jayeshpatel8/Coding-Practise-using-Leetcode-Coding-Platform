

int numDecodings(char * s){
    int len=strlen(s);
    if (!s) return 0;
    
    int dp[len];
    dp[0]=s[0]>'0';
    for (int i=1; i<len; i++)
        dp[i] = (s[i]>'0'?dp[i-1]:0) + ((s[i-1] == '1' || s[i-1] =='2' && s[i]<='6')? ((i-2<0)?1:dp[i-2]):0);
    return dp[len-1];
}