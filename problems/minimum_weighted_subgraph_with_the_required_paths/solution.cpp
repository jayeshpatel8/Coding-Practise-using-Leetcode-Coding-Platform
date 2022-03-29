class Solution {
public:
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        size_t max_v  = 1e10, ans = 1e10 + 1; 
        vector<vector<array<int, 2>>> g(n), grev(n);
        vector<size_t> dists1(n,max_v), dists2(n,max_v), distdest(n,max_v);
        for (auto & e : edges){
            g[e[0]].push_back({e[2],e[1]});
            grev[e[1]].push_back({e[2],e[0]});
        }
        dists1[src1]=dists2[src2]=distdest[dest] = 0;
        bfs(grev,dest,distdest);
        if (distdest[src1]==max_v || distdest[src2]==max_v)
            return -1;
        bfs(g,src1,dists1);
        bfs(g,src2,dists2);
        
        
        
        for (int i=0; i<n; i++){
            ans = min(ans, dists1[i] + dists2[i] +distdest[i] );
        }
        return ans;
        
    }
    void bfs( vector<vector<array<int, 2>>>& g,size_t src,vector<size_t> & dist){
        priority_queue<array<size_t, 2>,vector<array<size_t, 2>>,greater<array<size_t, 2>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            size_t i = p[1], d=p[0];
            if (d > dist[i]) continue;
            for (auto & p : g[i]){
                if (p[0] + d < dist[p[1]]){
                    dist[p[1]] = p[0] + d;
                    pq.push({dist[p[1]], (size_t)p[1]});
                }
            }
        }
    }
};