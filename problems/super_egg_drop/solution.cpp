class Solution {
public:
    int superEggDrop(int K, int n) {
        vector<int> dp(K+1);
        int drop=0;
        while(dp[K]  < n){
            drop++;
            for (int k=K; k>0 ; k--)
                dp[k] += dp[k-1] +  1;
        }
        return drop;
    }
};