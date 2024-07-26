class Solution {
public:
    int DT, N, ans = INT_MAX;
    
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<array<int,2>> G[100];
        DT=dt;
        N=n;
        for ( auto & e : edges ){
            G[e[0]].push_back({e[1],e[2]});
            G[e[1]].push_back({e[0],e[2]});
        }
        int ans=INT_MAX, node=-1;
        for (int i=n-1; i>=0; i--){
            int cnt = dfs(G,i,dt);
            if (cnt < ans){
                ans= cnt; node=i;
            }
        }
        return node;
    }
    int dfs(vector<array<int,2>> G[100],int u,int dt){
        vector<int> vis(N);
        priority_queue<array<int,2>, vector<array<int,2>>, greater<>> pq;
        pq.push({0,u});
        int cnt=-1;
        while(!pq.empty()){
            auto a = pq.top(); pq.pop();
            int u =a[1], w = a[0];
            if (w > dt ||  vis[u]) continue;
            if (++cnt >= ans) return cnt;
            vis[u] = 1;
            for (auto v : G[u]){
                int w1 = w + v[1];
                if (w1 > dt) continue;
                pq.push({w1,v[0]});
            }
            
        }
        return cnt;
    }
};
