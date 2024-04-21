class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n);
        vector<vector<int>> G(n);
        for (auto &e : edges){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(source);
        vis[source]=true;
        while (!q.empty()){
            auto u = q.front(); q.pop();
            if (u == destination) return true;
            for ( auto v : G[u]){
                if (vis[v]) continue;
                vis[v]=true;
                q.push(v);
            }
        }
        return false;
    }
};
