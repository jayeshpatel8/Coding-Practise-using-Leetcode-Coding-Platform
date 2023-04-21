class Solution {
public:
int dp[101][101][101], mod = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1, sizeof(dp));
        function<int(int ,int , int )> dfs = [&](int i, int num, int p)->int{

            if (i==group.size()) return 0;
            if (dp[i][num][p] != -1) return dp[i][num][p];
            long  ans = dfs(i+1,num,p);
            if ((num+group[i] <=n) )
                ans=  (ans  + dfs(i+1,min(100,num+group[i]),min(100,p+profit[i]))+ (p+profit[i]>=minProfit))%mod;
            return dp[i][num][p]=ans;
        };
        return dfs (0,0,0) + (minProfit==0);
    }
};