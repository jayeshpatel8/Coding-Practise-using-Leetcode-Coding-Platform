class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        // dp[i][j] = max(dp[i-1][k] + A[i][j] - abs(j-k)) for k=0 to n
        int m = points.size(), n = points[0].size();
        long long dp[m][n]; 
        for (int j=0; j<n; j++) dp[0][j] =  points[0][j];
        for ( int i=1; i<m; i++){
            vector<long long> r(n),l(n);
            l[0]= dp[i-1][0];
            for (int k=1; k<n; k++){
                l[k] = max(l[k-1] , ( dp[i-1][k]) + k );
            }
            r[n-1]=(dp[i-1][n-1]) -n +1;
            for (int k=n-2; k>=0; k--){
                r[k] = max(r[k+1], (dp[i-1][k]) - k );
            }        
            
            for (int j=0; j<n; j++){       
                dp[i][j] = max(l[j] - j ,r[j]+j) + points[i][j];
            }
        }
        return *max_element(dp[m-1],dp[m-1]+n);
    }
};