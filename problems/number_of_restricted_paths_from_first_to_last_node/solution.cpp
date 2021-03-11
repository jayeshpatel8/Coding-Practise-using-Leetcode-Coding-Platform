class Solution {
public:
    int N;
    vector<int> dp;
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> g(n+1);
        for (auto i : edges){
            g[i[0]].push_back({i[1],i[2]});
            g[i[1]].push_back({i[0],i[2]});
        }
        N=n;
        dp.resize(n+1,-1);
        vector<int> dis(n+1,INT_MAX);
        vector<int> vis(n+1,0);
        set<pair<int,int>> q;
        q.insert({0,n});
        dis[N]=0;
        
        while(!q.empty()){
            int u = q.begin()->second; q.erase(q.begin());
            vis[u]=true;
            for (auto &i : g[u]){                
                if(vis[i.first]==0 && (dis[u] + i.second <dis[i.first] )){                   
                    dis[i.first] = dis[u] + i.second;
                    q.insert({dis[i.first],i.first});
                }            
            }
        }
        return dfs(g,1,dis);
    }
    int MOD=1000000007;
    int dfs(vector<vector<pair<int,int>>>&g ,int u , vector<int> &dis){
        if(dp[u]!=-1) return dp[u];
        if(u==N) return 1;
        int cnt=0;
        for (auto & p : g[u]){
            if( dis[u] > dis[p.first]  )
                cnt  = (cnt+dfs(g,p.first,dis))%MOD;
        }
        return dp[u]=cnt;
    }
};