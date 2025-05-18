class Solution {
public:
    int dp[1001][1<<10]; // 4^5 = 2^10 == 1<<10
    int M,N,mod=1e9 + 7;
    int colorTheGrid(int m, int n) {
         M=m, N=n;
        memset(dp,0,sizeof(dp[0])*N);
        ways(0,0,0,0);
        return dp[0][0];   
    }
    
    int ways(int r, int c, int cur, int prev){
        
        if (c==N) return 1;
        if (r==M) return ways(0,c+1,0,cur);
        
        if (r==0 && dp[c][prev]) return dp[c][prev];
     
        int left = (prev >> r *2 )&0x3, up = (cur >>(r>0?(r-1)*2:0)) & 0x3, ans=0;
        for (int col=1; col<=3; col++)  {          
            if (col != left && col != up)
                ans = (ans + ways(r+1,c,cur|(col<< (r*2)),prev))%mod;            
        }
        
        if (r==0) dp[c][prev]=ans;
        return ans;
    }
}; 
