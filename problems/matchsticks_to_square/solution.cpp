class Solution {
public:
    int tot=0;
    int dp[1<<15];
    bool makesquare(vector<int>& ma) {
        tot = accumulate(begin(ma),end(ma),0L);
        if (tot%4) return false;
        sort(rbegin(ma),rend(ma));
        if (ma[ma.size()-1] > tot/4) return false;
        memset(dp,-1,sizeof(dp));
        return dfs(ma,0,tot/4);
    }
    int dfs(vector<int> &ma,int i, int sum,int mask = 0, int side = 0){
        if (side == 3) return true;
        if (dp[mask] != -1) return dp[mask];
        if (sum == 0)return dp[mask] = dfs(ma,0,tot/4,mask,side+1);
        for (int j=i; j<ma.size(); j++){
            if (0==(mask & (1<<j))  && sum >= ma[j] && dfs(ma, j+1, sum - ma[j] ,mask ^ (1<<j) ,side))
                return true;
        }
        
        return false;
    }
    
};