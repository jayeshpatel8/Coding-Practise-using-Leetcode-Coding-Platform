class Solution {
public:

    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> f(n);
        vector<vector<int>> G(n);
        for (auto & e: edges){
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
        }
        function<bool(int,int,int)> dfs = [&](int s, int e, int p){
                bool a=false;
                if (s==e) {
                    f[e]++;
                    return true;
                }
                for (int v : G[s]){
                    if (v==p) continue;
                    if (dfs(v,e,s)){ 
                        a=true;
                        break;
                    }
                }
                if (a)
                    f[s]++;
                return a;
            ;
        };
        int dp[51][2];
        memset(dp,-1,sizeof(dp));
        function<int(int,int,bool)> dfs2 = [&](int u, int p=-1,int half=false){
            if (dp[u][half] != -1) return dp[u][half] ;
            int ans = f[u] * price[u] , ans2 =   ans / 2;
            for (auto v : G[u]){
                if (v == p ) continue;
                ans += dfs2(v,u,false);
            }
            if (half) return dp[u][half]=ans;
            
            for (auto v : G[u]){
                if (v == p ) continue;
                ans2 += dfs2(v,u,true);
            }
            return dp[u][half] = min(ans,ans2);
        };
        for (auto i : trips){
            dfs(i[0],i[1],-1);
        }

        return dfs2(0,-1,false);
    }

};