class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n);
        for (auto &e : edges)
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);

        int ans = INT_MAX;
        
        function<int(int)> bfs = [&](int i){
            vector<int> vis(n,-1), dist(n,INT_MAX);
            
            queue<int> q; 
            q.push(i);
            dist[i]=0;
            int ans = INT_MAX;
            while (!q.empty()){
                int sz = q.size();
                while (sz-- > 0)
               {
                    int u = q.front(); q.pop();
                    for (auto v : G[u] ){
                        if (dist[v] == INT_MAX){
                            dist[v]=1 + dist[u];
                            vis[v]=u;
                            q.push(v);
                        }
                        else if (vis[v] != u && vis[u] != v){
                            ans = min(ans, dist[u] + dist[v] + 1);
                        }
                    }
                        
                }
            }
            return ans;
        };
        for (int i=0; i<n; i++){
            ans= min(ans, bfs(i));
        }
        return ans==INT_MAX ? -1 : ans;
    }
};