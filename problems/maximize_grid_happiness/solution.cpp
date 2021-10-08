
class Solution {
public:
    int M,N , dp[25][1024][7][7]={};
    int getMaxGridHappiness(int m, int n, int in, int ex) {
        M =m, N=n;
        return dfs(0,0,in,ex);
    }

    int dfs(int i, int mask, int in, int ex){
        
        if (i >= M*N || (in+ex)==0)  return 0;        
        if (dp[i][mask][in][ex]) return dp[i][mask][in][ex];
        int r = i/N, c = i%N, pos = 2*c;
        int newmask = mask & ~(3<<pos);
        int ans= dfs(i+1,newmask,in,ex);
        if (in)
            ans = max (ans, cost(r,c,mask,true) + dfs(i+1,newmask | 1<<pos ,in-1,ex));
        if(ex)
            ans = max (ans, cost(r,c,mask,false) + dfs(i+1,(newmask | 2<<pos) ,in,ex-1));
        
        return dp[i][mask][in][ex] = ans;
    }
    int cost(int i, int j, int mask, bool in){
        int pos = 2*j, 
            up = (mask & 3 << pos) >> pos, 
            prev = j==0? 0 : (mask & (3 <<(pos-2)))>>(pos-2);
        int res = (up == 0 ? 0 : up==1 ? -30 : 20) + 
                  (prev == 0 ? 0 : prev==1 ? -30 : 20);
        if(in)
            res += 120 - (up != 0 ? 30 : 0) - (prev != 0 ? 30 : 0);
        else
            res += 40 + (up != 0 ? 20 : 0) + (prev != 0 ? 20 : 0);
        return res;
    }
};