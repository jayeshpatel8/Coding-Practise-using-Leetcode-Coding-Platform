class Solution {
public:
    vector<vector<int>> ans;
    int time=0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n);
        vector<int> disc(n), low(n);// parent(n,-1);
        vector<vector<int>> G(n, vector<int>());
        for (auto &e : connections){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        for (int i=0; i<n;i++){
            if (vis[i]) continue;
            dfs(i,G,vis,disc,low,-1);
        }
        return ans;
    }
    void dfs(int u, vector<vector<int>>&G, vector<bool> &vis,vector<int> &disc, vector<int> &low, int parent){
        disc[u] = low[u] =++time;
        vis[u] = true;
        for (auto v : G[u]){
            if (parent == v) continue;
            if (!vis[v]){
                //parent[v]=u;
                dfs(v,G,vis,disc,low,u);
                //low[u] = min(low[v], low[u]);
                //if (low[v] > disc[u]){
                //    ans.push_back({u,v});
                //}
            }
            //else if (parent[u] != v){
                //low[u] = min(low[u], disc[v]);
            //}
            low[u] = min(low[v], low[u]);
            if (disc[u] < low[v])
                ans.push_back({u,v});
        }
    }
};