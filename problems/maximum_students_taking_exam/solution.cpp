class Solution {
public:
    int dp[8][1<<8] , N, M;
    int maxStudents(vector<vector<char>>& seats) {
        M= seats.size(), N=seats[0].size();
        memset(dp,-1,sizeof(dp));
        return dfs(seats,0,0);
    }
    int dfs (vector<vector<char>>& seats, int r, int pmask){

        if (r==M) return 0;            

        if (dp[r][pmask] != -1) return dp[r][pmask];
        
        int cmask =0 , ans =0 ;
        for (int i=0; i <N; i++) if (seats[r][i] == '.') cmask |= 1<<i;
        
        for (int i=0 ,mask=cmask & i; i<(1<<N); mask = cmask & ++i)
            if (!(mask & (mask>>1) || pmask & (mask<<1) || pmask & (mask>>1)))
                ans = max(ans, bitset(mask) + dfs(seats,r+1,mask));
        return dp[r][pmask] = ans;
    }
    int bitset(int n){
        int c=0;
        while(n) c++,  n&=n-1;
        return c;
    }
};