class Solution {
public:
    vector<int>  color;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color.resize(n,-1);
        for (int i=0; i<n; i++){
            if (color[i]==-1){
                
                    if(!dfs(graph,i,0)) return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, int i, int c){
        

        color[i]=c;
        for (auto u : graph[i]){
            if (color[u] == -1){
                if(!dfs(graph,u,c^1)) return false;
            }
            else if (color[u]==c) return false;
        }
        return true;
    }
};