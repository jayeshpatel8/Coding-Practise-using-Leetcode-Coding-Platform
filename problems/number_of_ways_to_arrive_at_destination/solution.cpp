typedef pair<long long, long long> pi;
class Solution {
public:
    int MOD = int(1e9) + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n+1);
        for (  auto i : roads){
            g[i[0]].push_back({i[2],i[1]});
            g[i[1]].push_back({i[2],i[0]});
        }
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vector<pair<long long,int>> dist(n, pair((long long)(1e18), 0));
        dist[0]={0,1};
        pq.push({0,0});

        while(!pq.empty()){
            auto [d, v] = pq.top();pq.pop();
           // if (d != dist[v].first) continue;
            for (auto  [d1 , v1] : g[v]){
                auto w = d1+d;
                if( w < dist[v1].first){
                   dist[v1] = {w, dist[v].second}; 
                    pq.push({w, v1});
                }
                else if(w == dist[v1].first)
                    dist[v1].second = (dist[v1].second + dist[v].second)%MOD;                 
            }
        }
        return dist[n-1].second;
    }
};