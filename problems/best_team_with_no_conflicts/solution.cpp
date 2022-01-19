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
        //memset(dp, -1, sizeof (dp));
        //return dfs(s,0,1000);
    }
    int dfs (vector<array<int,2>> & s, int i, int age){
        if (i >= N) return 0;
        if (dp[i][age] != -1) return dp[i][age];
        
        int ans = dfs(s,i+1,age);
        if (age >= s[i][1])
            ans = max(ans, s[i][0] + dfs (s,i+1,min(age,s[i][1])));
        
        return dp[i][age] = ans;
    }

}; 