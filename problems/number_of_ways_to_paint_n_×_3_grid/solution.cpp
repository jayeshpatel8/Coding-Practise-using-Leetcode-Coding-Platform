class Solution {
public:
    int dp[5001][4][4][4]={}, mod = 1e9 + 7;
    int numOfWays(int n, int r=0,int c=0, int c1=0, int c2=0, int c3=0) {
        if (r == n) return 1;
        if (c == 3) return numOfWays(n,r+1,0,c1,c2,c3);
        if(c==0 && dp[r][c1][c2][c3]!=0) return dp[r][c1][c2][c3];
        int ans=0;
        for (int col=1; col<=3; col++){
            if (c==0){
                if (col !=c1) ans = (ans + numOfWays(n,r,c+1,col,c2,c3))%mod;                
            } 
            else if (c == 1){
                if (col !=c1 && col !=c2) ans = (ans + numOfWays(n,r,c+1,c1,col,c3))%mod;
            }
            else{
                if (col !=c3 && col !=c2) ans = (ans + numOfWays(n,r,c+1,c1,c2,col))%mod;               
            }
        }
        if (c==0) dp[r][c1][c2][c3]=ans;
        return ans;
    }
};