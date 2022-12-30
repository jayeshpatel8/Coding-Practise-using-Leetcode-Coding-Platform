class Solution {
public:
vector<vector<int>> ans;
vector<int> path;
int N;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size()-1;  
        path.push_back(0);      
        dfs(graph,0);        
        return ans;
    }
    void dfs(vector<vector<int>>& graph, int u){
        if (u == N) {
            ans.push_back(path);
            return;
        }                
        for (auto v : graph[u]){
            path.push_back(v);
            dfs(graph, v);
            path.pop_back();
        }
    }
};