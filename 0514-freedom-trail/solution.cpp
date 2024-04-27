class Solution {
public:
int dp[101][101] , N;
    int findRotateSteps(string ring, string key) {
        N=ring.size();
        memset(dp,-1,sizeof(dp));
        return dfs(ring,key);
    }
    int dfs(string &ring,string &key, int ri =0, int ki = 0){
        if (key.size() == ki) return 0;
        if (dp[ri][ki]!=-1) return dp[ri][ki];
        int ans = INT_MAX;
        for (int i=0; i<N; i++){
            if (ring[i] == key[ki]){
                int step =  abs(ri-i);
                step = min (step, N-step);
                ans = min(ans, step + 1 + dfs(ring,key,i, ki+1));
            }
        }
        return dp[ri][ki]  =ans;
    }
};
