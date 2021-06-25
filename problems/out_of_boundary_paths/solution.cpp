class Solution {
public:
    int M,N;
    
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        long count =0;
        int prev[51][51]={0};
        prev[startRow][startColumn]=1;
        for (int move = 1; move<=maxMove; move++){
            int cur[51][51]={0};
            for(int i=0; i<m; i++){
                for (int j=0; j<n;j++){
                    if (i==0 )count = (count + prev[i][j])%mod;
                    if (j==0)count = (count + prev[i][j])%mod;
                    if (i==m-1)count = (count + prev[i][j])%mod;
                    if (j==n-1) count = (count + prev[i][j])%mod;
                   {
                        cur[i][j] = (cur[i][j] + (i<m-1?(long)prev[i+1][j] : (long)0 )
                                    + (i>0? prev[i-1][j]:0)
                                    + (j<n-1 ? prev[i][j+1]:0)
                                    + (j>0 ? prev[i][j-1]:0)) %  mod;                                         
                    }
                }
            }
            swap(prev,cur);
        }
        return count;
    }

}; 
/*
class Solution {
public:
    int M,N;
    int dp[52][52][52];
    int mod = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M=m;
        N=n;
        memset(dp,0xff,sizeof(dp));
        return path(startRow, startColumn,maxMove);
    }
    
    int path(int i , int j, int move){
        
        if (i<0 || j<0 || i>=M || j>=N) return 1;
        if (move == 0) return 0;
        if (dp[i][j][move] != -1) return dp[i][j][move];
          int m = move-1;;
        return dp[i][j][move] =  (
                  
                    (long)path(i+1,j,m) 
                    + path(i-1,j,m)
                    + path(i,j+1,m)
                    + path(i,j-1,m)
                ) % mod;
        
    }
}; 
*/