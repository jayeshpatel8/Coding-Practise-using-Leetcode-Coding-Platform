class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs),end(pairs));
        int dp[1000];

        dp[0]=1;
        for ( int i = 1; i<pairs.size(); i++){
            dp[i]=1;
            for ( int j=i-1; j>=0; j--){
                if (pairs[j][1] < pairs[i][0])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        int ans=1;
        for(int i=1; i<pairs.size(); i++)
           ans = max(ans, dp[i]);

        return ans;
    }
};