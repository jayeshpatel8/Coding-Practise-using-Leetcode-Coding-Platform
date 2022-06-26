class Solution {
public:
    int distinctSequences(int n) {
        int dp [10001][7][7];
        memset(dp,0,sizeof dp);
        int mod = 1e9 + 7;
        dp[0][0][0]=1;
        for (int i=1; i<=n; i++ ){
            for (int  x =0; x<=6; x++)
                for (int y = 0; y<=6; y++){
                    for (int z = 1; z<=6; z++){
                        if (y !=0 && __gcd(y,z) > 1 ); 
                        else if (z==y ||z==x);
                        else
                            (dp[i][y][z] +=dp[i-1][x][y])%=mod;
                    }
                }
        }
        long ans = 0;
        for (int i=0; i<=6; i++)
            for(int j=0; j<=6; j++)
                ans = (ans + dp[n][i][j]) %mod;
        return ans;
    }
};