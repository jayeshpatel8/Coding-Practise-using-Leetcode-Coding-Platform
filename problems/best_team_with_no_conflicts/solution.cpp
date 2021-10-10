class Solution {
public:
     int dp[1000];
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int N = scores.size();
        vector<pair<int,int>> P(N);
         for ( int i =0; i<N; i++)
             P[i] ={ages[i], scores[i]};
         sort(begin(P), end(P));
        
        int ans = dp[0] = P[0].second;
        for( int i=1; i<N; i++){
            dp[i]=P[i].second;
            for ( int j=0; j<i;j++){
                if (P[i].second >= P[j].second)
                    dp[i] = max(dp[i], dp[j] + P[i].second);
                ans = max(ans, dp[i]);
            }
        } 
        return ans;
    }
};