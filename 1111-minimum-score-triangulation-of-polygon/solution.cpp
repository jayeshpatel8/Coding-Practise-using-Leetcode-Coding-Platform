class Solution {
public:
    int minScoreTriangulation(vector<int>& V) {
        int dp[101][101]={};
        
        for (int i = V.size()-1; i>=0; i--){            
            for (int j = i+1; j< V.size(); j++){
                int ij = V[i] * V[j];
                for ( int k = i+1; k<j; k++)
                    dp[i][j] = min(dp[i][j]==0? INT_MAX: dp[i][j], dp[i][k] + ij * V[k] + dp[k][j]);
            }
        }
        return dp[0][V.size()-1];
    }
};
