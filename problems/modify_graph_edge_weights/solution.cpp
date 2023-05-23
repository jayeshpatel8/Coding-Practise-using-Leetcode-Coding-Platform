
#if 1
class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int dest, int target) {
        vector<vector<int>> G(n, vector<int>(n));
        

        for (auto &e : edges)
            if (e[2]!=-1)
                G[e[0]][e[1]]=G[e[1]][e[0]]=e[2];
        vector<int> src_dist(n, INT_MAX),dist2(src_dist),par(n,-1); 
        src_dist[source] = dist2[source]=0; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        pq.emplace(0, source); 
        auto bfs = [&]()->void{
            while (!pq.empty()){
                auto [d,u] =pq.top(); pq.pop();
                if (d == src_dist[u]){
                    for (auto v=0; v<n; v++){
                        if (G[u][v] && src_dist[v] > d + G[u][v]){
                            src_dist[v] = d + G[u][v];
                            pq.push({src_dist[v],v});
                        }
                    }
                }
            }
        };
        
        bfs();
                
        if (src_dist[dest]< target ) return {};
        if (src_dist[dest] == target ) {
            for (auto &e : edges)
                if (e[2]==-1) e[2]= 2e9;
            return edges;        
        }

        for (auto &e : edges)
            if (e[2]==-1)
                G[e[0]][e[1]]=G[e[1]][e[0]]=e[2];

        pq.emplace(0, source); 
        {
            while (!pq.empty()){
                auto [d,u] =pq.top(); pq.pop();
                if (u == dest) {
                    if (d > target) return {}; 
                    break;
                }
                if (d == dist2[u]){
                    for (auto v=0; v<n; v++){
                        int w = G[u][v] == -1? 1:  G[u][v];
                        if (w && dist2[v] > d + w){
                            dist2[v] = d + w;
                            pq.push({dist2[v],v});
                            par[v]=u;
                        }
                    }
                }
            }
        }      
        
        for (int u=dest; u>=0 && par[u] >=0 ; u=par[u]){
            int v = par[u];            
            if (G[u][v]==-1){
                if (src_dist[v] < target) {
                    G[u][v]=G[v][u]=target-src_dist[v];break;
                }
                G[u][v]=G[v][u]=1;
            }
            target -= G[u][v];
        }
        vector<vector<int>> ans; 
        for (auto& e : edges) {
            if (G[e[0]][e[1]] == -1) G[e[0]][e[1]] = 2e9; 
            ans.push_back({e[0], e[1], G[e[0]][e[1]]}); 
        }
        return ans;
    }
};
#endif