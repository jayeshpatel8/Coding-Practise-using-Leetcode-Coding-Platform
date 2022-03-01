class Solution {
public:
    int dp [1001]={},best[1001]={}, mlap=0;
    
    int minimumFinishTime(vector<vector<int>>& tires, int ct, int nLaps) {
        int N = tires.size(),l;
         for(auto & tire : tires){
             l=1;
            for (long lapt= tire[0] ,t = tire[0], m =  ct + tire[0]; l <=nLaps && lapt < m; t+=lapt,l++){
                if (best[l]==0 || best[l] > t)
                    best[l] = t;
                lapt *= tire[1];
            }
             mlap=  max(mlap,l-1);
        }        
        return dfs(nLaps,ct);
    }
    int dfs(int nLaps, int ct){
        if (nLaps == 0) return -ct;
        
        if (dp[nLaps]) return dp[nLaps];
        
        int ans= INT_MAX;
        for(int j=1; j<=min(nLaps,mlap); j++)
            ans  = min (ans, ct + best[j] + dfs(nLaps-j,ct));
        
        
        return dp[nLaps] = ans;
        
    }
};