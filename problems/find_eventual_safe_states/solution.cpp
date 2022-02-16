class Solution {
public:
    int N;
    vector<bool> ter;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        N=graph.size();
        ter.resize(N);
        vector<int> ans;
        vector<bool> vis(N);
        for (int i=0; i<N; i++){
            if (dfs(graph,vis,i))
                ans.push_back(i);
        }
        return ans;
    }
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int u){
        if (vis[u]) return ter[u];
        bool res=true;
        vis[u]=true;
        for (int j=0; j<graph[u].size() && res ; j++){
            int v = graph[u][j];            
            res = vis[v] ? ter[v] : dfs(graph,vis,v);
        }
        return ter[u]=res;
    }
};