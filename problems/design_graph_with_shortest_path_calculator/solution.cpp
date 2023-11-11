class Graph {
public:
    vector<vector<array<int,2>>>G;
    Graph(int n, vector<vector<int>>& edges) {
        G.resize(n);
        for (auto & e : edges)
            G[e[0]].push_back({e[1],e[2]});
    }
    
    void addEdge(vector<int> e) {
        G[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int node1, int node2) {
        int N= G.size();
        priority_queue<array<int,2>>pq;
        pq.push({0,node1});
        vector<int> cost(N, INT_MAX);
        cost[node1]=0;

        while (!pq.empty()){
            auto [c,u] = pq.top(); pq.pop();
            if (u ==node2) break;
            for (auto [v,nc] : G[u]){
                if (cost[v] > nc + -c){
                    cost[v]  = nc + -c;
                    pq.push({-cost[v],v});
                }
            }
        }
        return cost[node2] != INT_MAX ? cost[node2] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */