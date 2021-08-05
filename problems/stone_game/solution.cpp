class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        vector<int> dp(piles);
        for ( int l=1; l<N; l++){
            for (int i = 0; i<N-l; i++){
                int  j = i+l;
                dp[i] = max(piles[i] - dp[i+1], piles[j] - dp[i]);
            }
        }
        return dp[0] > 0 ;
    }
};