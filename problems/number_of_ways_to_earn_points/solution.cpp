class Solution {
public:
    int dp[1001][51], mod  =  1e9 + 7;
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        memset(dp,-1,sizeof(dp));
        return dfs(target, types , 0);    
    }
    int dfs(int t, vector<vector<int>>& types, int i){
        if (i >= types.size() ) return t == 0;
        if (dp[t][i]!=-1) return dp[t][i];
        long long ans = dfs(t,types,i+1);
        int cnt = types[i][0], v = types[i][1];
        for (int j=0 , sum = 0; j<cnt; j++){
            sum += v;
            if (t>=sum)
                ans =  (ans + dfs(t-sum,types,i+1))  % mod;
            else
                break;
        }
        
        return dp[t][i] =  ans ;      
    }
};