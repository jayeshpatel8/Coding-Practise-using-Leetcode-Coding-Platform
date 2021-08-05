class Solution {
public:
    int dp[1002][1002]={} , psum[1002];
    int stoneGameVII(vector<int>& stones) {
        psum[0]=0;
        for (int i=0; i<stones.size(); i++) 
            psum[i+1] = stones[i]+psum[i];
        
        for (int l=1; l<stones.size(); l++){
            for (int i=0; i<stones.size()-l; i++){
                int  j = i+l;
                dp[i][j] = max( psum[j+1] - psum[i+1] - dp[i+1][j],
                                psum[j] - psum[i] - dp[i][j-1]);
            }
        }
        return dp[0][stones.size()-1];
    }
};