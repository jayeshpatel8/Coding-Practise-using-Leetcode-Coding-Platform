class Solution {
public:
vector<bool> vis;
    int minReorder(int n, vector<vector<int>>& conn) {
        vector<vector<array<int,2>>> G(n);
        vis.resize(n);
        for (auto & e: conn){
            G[e[0]].push_back({e[1],0}), G[e[1]].push_back({e[0],1});
        }
        vis[0]=true;
        return dfs(G,0);
    }
    int dfs(vector<vector<array<int,2>>>& G, int u){
        int cnt = 0;
        for (auto & v : G[u]){
            if (!vis[v[0]]){
                vis[v[0]]=true;
                cnt += (v[1]==0) + dfs(G,v[0]);
            }
        }
        return cnt;
    }
};