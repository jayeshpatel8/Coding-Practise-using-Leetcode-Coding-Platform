class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> dist(n,-1.0);
        vector<pair<int,double>> G[n];
        for (auto i=0; i< edges.size(); i++){
            auto e = edges[i];
            G[e[0]].push_back({e[1],succProb[i]}),G[e[1]].push_back({e[0],succProb[i]});
        }
        priority_queue<pair<float,int>> pq;
        pq.push({1,start});

        while(!pq.empty()){
            auto [p, u] = pq.top(); pq.pop();
            if (u == end) return p;
            for (auto &[v,p1] : G[u]){
                if (p1 * p <= dist[v]) continue;
                dist[v] = p1 * p ;
                pq.push({dist[v], v});
            }
        }
        return 0;
    }
};
