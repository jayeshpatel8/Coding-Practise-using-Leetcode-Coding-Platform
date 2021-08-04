class Solution {
public:
    vector<vector<int>> dp;
    int M, N;
    int maxStudents(vector<vector<char>>& seats) {
        M = seats.size(), N = seats[0].size();
        dp.resize(M,vector<int>(1<<N,-1));
        return dfs(seats);
    }
    int dfs(vector<vector<char>>& seats, int i = 0, int pmask = 0){
        if(i==M) return  0;
        if (dp[i][pmask] !=  -1) return dp[i][pmask];
        int ans = 0, cur=0;
        
        for (int k=0; k < N; k++)  if (seats[i][k] != '#')  cur |= (1<<k);
        
        for ( int j=0, mask = cur & j; j< (1<<N); mask = cur & ++j){
            if (!(mask & (mask >> 1) || (pmask & (mask<<1)) || pmask & (mask>>1)) )
                ans  = max(ans,cntbits(mask) +  dfs(seats,i+1,mask));
        }
        return dp[i][pmask] = ans;
    }
    int cntbits(int n, int cnt=0){        
        while(n) ++cnt, n&=n-1;
        return cnt;
    }
};