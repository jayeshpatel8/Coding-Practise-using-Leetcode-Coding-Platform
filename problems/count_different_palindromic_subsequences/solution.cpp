class Solution {
public:
    int dp[1001][1001][4], mod  = 1e9 + 7, ch[4]={'a','b','c','d'};
	int countPalindromicSubsequences(string s) {
		
		memset(dp,-1,sizeof(dp));
		int ans=0;
		
		for(int i=0;i<4;i++){
			ans= (ans + pal(s,0, s.size()-1, i))% mod;
        }
		return ans;        
	}
    int pal(string & s, int i, int j, int c){
        if (i>j) return 0;
        if (i==j) return s[i]==ch[c];
        if(dp[i][j][c] != -1 ) return dp[i][j][c];
        long ans = 0;
        
        if (s[i]==s[j] && s[i]==ch[c]){
            ans  =  2;
            for ( int k=0; k<4; k++)
                ans =(ans +  pal(s,i+1,j-1,k))%mod;
        }
        else{
            ans = pal(s,i+1,j,c) + pal(s,i,j-1,c) - pal(s,i+1,j-1,c);
        }
        return dp[i][j][c] = ans % mod;
    }
};
