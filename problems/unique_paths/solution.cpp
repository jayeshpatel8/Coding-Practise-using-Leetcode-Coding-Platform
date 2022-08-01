class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            total possible step = m + n - 2;
            out of this we can take right on n-1 step;
            nCr = (m+n-2) choose (n-1)
        */
        if (m < n) swap(m,n);
        long long ans = 1;
        for (int i=1, j =n; j<m+n-1; i++,j++){
            ans *= j;
            ans /= i;
        }
        return ans;
    }

    int uniquePaths2(int m, int n) {
        int dp[101][101]={};
        dp[0][1]=1;
        for (int i=1; i<=m; i++){
            for (int j=1; j<=n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};