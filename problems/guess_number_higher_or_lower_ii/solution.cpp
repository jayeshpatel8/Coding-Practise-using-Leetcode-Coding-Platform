class Solution {
public:
    int dp[201][201];
    int getMoneyAmount(int n) {
        memset(dp,0,sizeof(dp));
        for ( int l=2; l<=n;l++){
            for ( int i=1; i+l-1<=n; i++){
                int j=i+l-1;
                dp[i][j] = INT_MAX;
                for ( int k=i; k<j; k++){
                    dp[i][j] =  min (dp[i][j], k + max(dp[i][k-1],dp[k+1][j]));
                }
            }
        }
        return dp[1][n];
    }
    int select(int start, int end){
        if (start >= end) return 0;
        if (dp[start][end]) return dp[start][end];
        int mingain=INT_MAX;
        for ( int i=(start+end)/2; i<=end; i++){
            mingain = min(mingain, i + max(select(start, i-1), select(i+1,end)));
        }
        return dp[start][end] = mingain;
    }

};