class Solution {
public:
    int dst;
    vector<vector<int>> ans;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dst = graph.size()-1;
        
        vector<int> path(1);
        dfs(graph,0,path);
        return ans;
    }
    void dfs(vector<vector<int>>& graph, int u , vector<int>& path){
        if (u == dst){
            ans.push_back(path);
            return;
        }
        for (auto v : graph[u]){
            path.push_back(v);
            dfs(graph,v,path);
            path.pop_back();
        }
    }
};