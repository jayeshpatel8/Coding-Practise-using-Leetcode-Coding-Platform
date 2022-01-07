class Solution {
public:
    int dp[5][5][1024][7][7]={}, m, n ;
    int getMaxGridHappiness(int m1, int n1, int introvertsCount, int extrovertsCount) {
       
        //  1 ext, 2 int, 0 empty
        m=m1, n=n1;
        return dfs(0,introvertsCount,extrovertsCount, 0,0);
    }
    int dfs(int mask, int intv, int extv, int i, int j){
        
        if (j==n)  i++,j=0;
        
        if (i==m) return 0;
        
        if (dp[i][j][mask][intv][extv]) return dp[i][j][mask][intv][extv];
       
        int pos= 2*j, nmask = mask & ~(3 << pos);        
        int up =(mask & (3<<pos))>>pos, prev = j==0?0: (mask & (3<<(pos-2)))>>(pos-2);
        
        int ans= dfs(nmask,intv,extv,i,j+1);;
        if (extv){
            int s=40;
            if (i>0 && up) s += getscore(1,up)  ;
            if (j>0 && prev) s += getscore(1,prev);        
            ans = max (ans, s + dfs(nmask|1<<pos,intv,extv-1,i,j+1));
        }
        if (intv){
            int s=120;
            if (i>0 && up ) s += getscore(2,up);
            if (j>0 && prev ) s += getscore(2,prev);

           
            ans = max (ans, s + dfs(nmask|2<<pos,intv-1,extv,i,j+1));
        }        
        
        return dp[i][j][mask][intv][extv] = ans;
    }
    int getscore(int a, int n){
        int s=0;
        {
            if (a == 1) s+=20;
            else s-=30;
            if (n==1) s+=20;
            else s-=30;
        }
        return s;
    }
};