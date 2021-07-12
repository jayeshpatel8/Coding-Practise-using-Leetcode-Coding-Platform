class Solution {
public:
    int N;
    int dp[1 << 20];
     
    bool canIWin(int maxInt, int total) {
        if (total <= maxInt) return true;
        if ((maxInt*(1+maxInt)/2)<total) return false;
        
        N = maxInt;
        
        
        return dfs(total, 0);
    }
    bool dfs(int total, int bits){        
        if (total<=0) return false;
        if (dp[bits]!= 0) return dp[bits]>0;
        
        for (int i=0; i<N; i++)
            if ((bits & 1 << i) == 0 && !dfs(total-(i+1), bits | 1 << i)) 
                return dp[bits]=true;                             
        dp[bits]=-1;
        return false;
    }
};