class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(begin(clips),end(clips));
        
        int dp[101];
        dp[0]=0;
        for (int i=1; i<=time; i++) dp[i] = 101;
        
        for ( auto i : clips){
            for ( int e = i[0]+1; e<=i[1]; e++)
                dp[e] = min(dp[e], 1 + dp[i[0]]);
        }
        return dp[time]==101? -1 : dp[time];
    }
};