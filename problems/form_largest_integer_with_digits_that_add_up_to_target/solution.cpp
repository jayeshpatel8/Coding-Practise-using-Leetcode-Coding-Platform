class Solution {
public:
    int dp[5001];
    
    string largestNumber(vector<int>& cost, int target) {
        //memset(dp,-1,sizeof(dp));
        //if (dfs(cost,target) <=0) return "0";
        dp[0]=0;
        for (int t=1; t<=target; t++){
            dp[t] = INT_MIN;
            for(int j=0; j<9; j++){
                if(t >= cost[j]){
                    dp[t] =max (dp[t], 1 + dp[t - cost[j]]);
                }
            }
        }
        if (dp[target] < 0) return "0";
        string ans;
        for (int  i =8; i>=0; i--){
            while(target >= cost[i] && (dp[target-cost[i]]+1 == dp[target])){
                ans += i+1+'0';
                target -=cost[i];
            }
        }
        return ans;
    }
    int dfs(vector<int>& cost, int target){
        if (target == 0) return dp[0]=0;
        if (dp[target] != -1) return dp[target];
       
        int ans = -5001;
        for (int j= 0; j<=8; j++){
            if(target >= cost[j])
                ans = max(ans, 1 + dfs(cost,target-cost[j]));
        }
        return dp[target] =ans;
    }
};