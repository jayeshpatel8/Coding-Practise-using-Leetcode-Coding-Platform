class Solution {
public:
    int dp[1001][1001], N;
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        N = scores.size();
        int ans = 0;

        vector<array<int,2>> s(N);
        for ( int i=0; i<N; i++)
            s[i]= {scores[i], ages[i]};
        sort(rbegin(s),rend(s));
        vector<int> dp1(N);
        for (int i=0; i<N; i++){
            dp1[i] = max(dp1[i], s[i][0]);
            int age = s[i][1];
            for (int j=i+1; j<N; j++)
                if (age >= s[j][1])
                    dp1[j] = max(dp1[j] , dp1[i] + s[j][0]);
            ans = max(ans , dp1[i]);
        }
        return ans;
    }
};