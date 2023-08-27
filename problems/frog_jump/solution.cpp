class Solution {
public:
int dp[2001][2001];
unordered_map<int,int> idx;
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        for (int i=0; i<stones.size(); i++) idx[stones[i]]=i;
        memset(dp,-1, sizeof(dp));
      
        return dfs(stones, 1, 0);
    }
    bool dfs(vector<int> & stones, int i, int prev){        
        if (i>=stones.size()-1) return 1;
        if (dp[i][prev] != -1) return dp[i][prev];
        int ans= 0;
        for (int j=0,next=stones[i] + stones[i]-stones[prev]-1; j<3; j++,next++){
            if (next > stones[i] && idx.count(next) && dfs(stones,idx[next],i)){
                ans=1;break;
            }
        }
        return dp[i][prev]=ans;
    }
};