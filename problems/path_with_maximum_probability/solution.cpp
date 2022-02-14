class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> G[n];
        for (int i=0; i< edges.size(); i++ ){
            int u = edges[i][0] ,v = edges[i][1] ;
            double w = succProb[i];
            G[u].push_back({v,w});
            G[v].push_back({u,w});
        }
        queue<int> q;
        q.push(start);
        vector<double> p(n);
        p[start]=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz-- > 0){
                int u = q.front(); q.pop();
                for (auto & [v,w] : G[u]){
                    if (p[v] < p[u] * w){
                        p[v] = p[u] * w;
                        q.push(v);
                    }
                }
            }
        }
        return p[end];
    }
};