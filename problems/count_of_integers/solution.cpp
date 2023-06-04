
class Solution {
public:
int dp[23][2][2][401] ,mod = 1e9 +7;
string s1, s2;
    int count(string num1, string num2, int min_sum, int max_sum) {
        memset(dp,-1, sizeof(dp));
        s1 = string(num2.size()-num1.size(),'0') + num1;
        s2 = num2;
        
        int a = dfs(0,1,1,max_sum);
        return a - dfs(0,1,1,min_sum-1);
    }
    int dfs(int i, int lim1, int lim2, int sum){
        if (sum < 0) return 0;
        if (i >= s2.size()) return 1;
        if (dp[i][lim1][lim2][sum] != -1) return dp[i][lim1][lim2][sum];
        long long ans = 0;
        int start = lim1 ? s1[i]-'0' : 0;
        int end = lim2 ? s2[i]-'0' : 9;

        for (int d =start; d <= end; d++){
            ans =  (ans  + dfs (i+1,lim1 & (start == d), lim2 & (end == d), sum - d))%mod;
        }
        return dp[i][lim1][lim2][sum] =ans;
    }
};
