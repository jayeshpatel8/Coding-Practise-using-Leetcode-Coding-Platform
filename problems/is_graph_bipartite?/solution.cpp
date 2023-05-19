class Solution {
public:
    int vis[101]={};
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        for (int u=0; u<n; u++)
            if (!vis[u])
                if (!dfs(graph, u)) return false;

        return true;
    }
    bool dfs(vector<vector<int>>& graph,int u,int cnt=1) {
        if (vis[u])
            return (vis[u]&1) == (cnt&1);
        
        vis[u]=cnt++;
        for (auto v : graph[u])
            if (!dfs(graph,v,cnt)) return false;
        
        return true;
    }
};