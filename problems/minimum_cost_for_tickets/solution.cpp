class Solution {
public:
int dp[366];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));

        function<int(int)> dfs = [&](int i){
            if (i>=days.size()) return 0;
            if (dp[i]!= -1) return dp[i];
            int ans = costs[0] + dfs(i+1);
            ans=  min(ans, costs[1] + dfs(lower_bound(begin(days)+i,end(days),days[i]+7)-begin(days)));
            ans=  min(ans, costs[2] + dfs(lower_bound(begin(days)+i,end(days),days[i]+30)-begin(days)));            
            return dp[i] =ans;
        };
        return dfs(0);
    }

};