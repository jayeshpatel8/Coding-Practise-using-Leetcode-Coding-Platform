#define pi pair<int, int>
class Solution {
public:
    
    
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<pi> g[n];
        int dist[n], ans =0;
        dist[0]=0;
        for (int i = 1; i < n; ++i) dist[i] = maxMoves+1;
        for ( auto &e : edges){
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        //map<pi,int> used;
        priority_queue<pi ,vector<pi>,greater<pi>> pq; // {distance , node}
        pq.push({0,0});
        while(!pq.empty()){
            pi top = pq.top(); pq.pop();
            int d = top.first, u = top.second;
            
            if( d > dist[u]) continue;                       
            
            for(auto nei : g[u]){
                int v = nei.first, d1 = nei.second;
                //used[{u,v}] = min(d1,maxMoves-d);
                
                int d2 = d + d1 + 1;
                if (d2 < dist[v]){
                    dist[v] = d2;
                    pq.push({d2,v});
                }
            }
        }
        for(int i=0; i<n; i++) ans += dist[i]<=maxMoves;
        for ( auto &e : edges){
            int a = min(dist[e[0]] <=maxMoves? maxMoves-dist[e[0]]: 0,e[2]);
            int b = min(dist[e[1]] <=maxMoves? maxMoves-dist[e[1]]: 0,e[2]);
            ans += min(e[2],a+b);
        }
        return ans;
    }
};