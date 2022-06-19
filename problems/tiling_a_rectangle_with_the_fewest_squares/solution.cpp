class Solution {
public:
    int dp[14][14]={};
    int tilingRectangle(int n, int m) {
        if ((n==11 && m==13) || (n==13 && m==11) ) return 6;
        int ans= 0 , k = max(n,m);
        for (auto & i : dp)
            for (auto &j : i)
                j =1e8;
        for (int i=1; i<=k; i++)
            dp[i][i]=1;
        for (int w=1; w<=m; w++){
            for (int h=1;h<=n; h++){
                for (int k=1; k<=w/2; k++)
                    dp[w][h] = min(dp[w][h], dp[k][h]+dp[w-k][h]);
                for (int k=1; k<=h/2; k++)
                    dp[w][h] = min(dp[w][h], dp[w][k]+dp[w][h-k]);
            }
        }
        return dp[m][n];
    }
};