class Solution {
public:
    int dp[13][(1<<12)], M,N, mcost[12];
    int connectTwoGroups(vector<vector<int>>& cost) {
        memset(dp,-1,sizeof(dp));
        M = cost.size();
        N= cost[0].size();
        for (int j=0; j<N; j++) mcost[j]=INT_MAX;
        for ( auto & i : cost){
            int c = 0;
            for( auto j : i)
                mcost[c++] = min(mcost[c],j);
        }
        return dfs(cost,0,0);
    }
    int dfs(vector<vector<int>>& cost, int i, int mask){
        if(dp[i][mask] != -1) return dp[i][mask];
        if(i>=M){
            if (mask == (1<<N)-1) return 0;
            int res = 0;
          for ( int j =0; j<N; j++)  
              if ((mask  & (1<<j)) == 0)
                  res +=mcost[j];
           return dp[i][mask] = res; 
        } 

        int ans = INT_MAX;
        for (int j = 0; j<N; j++){
            ans = min(ans, cost[i][j] + dfs(cost,i+1,mask|(1<<j)));
        }
        return dp[i][mask] = ans  ;
    }
};