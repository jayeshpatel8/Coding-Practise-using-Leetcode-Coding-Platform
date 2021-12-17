class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int N = matrix[0].size(),M=matrix.size();
        
            int ans=0;
        vector<vector<int>>dp(M+1,vector<int>(N+1,0));
        for (int i=1; i<=M; i++){
        
        for (int j=1; j<=N; j++){
            
            if ( matrix[ i-1][ j-1] =='1'){
                dp[i][j] = min({ dp[i][j-1],dp[i-1][j-1],dp[i-1][j]})+1;
            }
            ans = max(ans ,dp[i][j]);
                
        }
    }
        return ans * ans;
    }
};