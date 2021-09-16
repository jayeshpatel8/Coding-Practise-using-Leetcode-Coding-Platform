class Solution {
public:
    int N,H ,mod=1e9 + 7;
    //int dp[41][1<<11];
    vector<int> h[41];
    int numberWays(vector<vector<int>>& hats) {
        N  = hats.size();
        
        for ( int i=0; i<hats.size(); i++){            
            for (auto j : hats[i])
                h[j].push_back(i);            
        }        
        vector<int> dp1(1<<N, 0);
        dp1[0]=1;
        for( int i =1; i<=40; i++){
            for ( int s=(1<<N)-1; s>=0; s--){
                for (auto j : h[i]){
                    if ((s & (1 << j)) == 0)
                        dp1[s | (1 << j)] = (dp1[s | (1 << j)] + dp1[s] )%mod;            
                }
            }
        }
        return dp1[(1<<N)-1];
    }
    /*
    int numberWays(vector<vector<int>>& hats) {
        N  = hats.size();
        memset(dp,-1,sizeof(dp));
        for ( int i=0; i<hats.size(); i++){            
            for (auto j : hats[i])
                h[j].push_back(i);            
        }
        
        return dfs(1,0);
    }
    int dfs(int i, int mask){
        if (mask == (1 << N)-1) return 1;
        if (i >= 41) return 0;
        if(dp[i][mask] != - 1) return dp[i][mask];
        int ans = dfs(i+1,mask);
        for (auto j : h[i]){
            if (mask & (1<<j)) continue;
            ans = (ans + dfs(i+1,mask | (1<<j)))%mod;            
        }

        return dp[i][mask] = ans;
    }*/
};