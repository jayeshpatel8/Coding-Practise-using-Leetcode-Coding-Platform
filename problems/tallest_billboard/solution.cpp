class Solution {
public:
    int dp[20][50001], sum = 0 ;;
    int tallestBillboard(vector<int>& rods) {
     
        for (auto i : rods) sum+=i;
        sum /= 2;
        memset(dp,-1,sizeof(dp));
        int ans = dfs(rods)/2;
        return ans <= 0 ? 0 : ans;
    }
    int dfs(vector<int>&  rods, int i=0, int s1 = 0, int s2 = 0){
        if(i >= rods.size()) return s1==s2? 0 : -50001;
        if(s1 > sum || s2 >sum) return -50001;
        if(dp[i][abs(s1-s2)] != -1) return dp[i][abs(s1-s2)];
        return dp[i][abs(s1-s2)] =  max(dfs(rods,i+1,s1,s2)
                                    , rods[i] + max(dfs(rods,i+1,s1+rods[i],s2)
                                                ,dfs(rods,i+1,s1,s2+rods[i])));
    }
};