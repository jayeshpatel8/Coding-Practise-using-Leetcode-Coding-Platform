class Solution {
public:
    vector<bool> vis;
    long long countPairs(int n, vector<vector<int>>& edges) {
        vis.resize(n);
        vector<vector<int>> G(n);
        for (auto & e : edges)
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
        long long ans = 0,   rem = n;
        for (int i=0; i<n; i++){
            if (!vis[i]){
                vis[i]=true;
                long long c = dfs(G,i) + 1;
                rem -= c;
                ans = (ans + rem * c);
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>> & G, int u){
        int ans = 0;
        for (auto v : G[u]){
            if (vis[v]) continue;
            vis[v]=true;
            ans += 1 + dfs(G,v);
        }
        return ans;
    }
};