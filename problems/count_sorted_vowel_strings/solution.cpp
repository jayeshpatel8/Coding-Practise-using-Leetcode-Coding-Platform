class Solution {
public:
    int countVowelStrings(int n) {
        int dp[6] = {0, 1,1,1,1,1};
        for ( int i=1; i<n; i++){
            for ( int j = 1; j<=5; j++){
                dp[j] += dp[j-1]; 
            }
        }
        return accumulate(begin(dp),end(dp),0L);
    }
};