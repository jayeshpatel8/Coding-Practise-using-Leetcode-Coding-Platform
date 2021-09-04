class Solution {
public:
    int N;
    vector<int> count,sum;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        sum.resize(N); count.resize(N,1);
        vector<vector<int>> graph(n);
        for ( auto e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(graph,0,-1);
        dfs2(graph,0,-1);
        return sum;
    }
    void dfs(vector<vector<int>> &graph, int root, int parent){
        for (auto c : graph[root]){
            if( c != parent){
                dfs(graph,c,root);
                sum[root] += sum[c]+count[c];
                count[root] +=count[c];
            }
        }
    }
    void dfs2(vector<vector<int>> &graph, int root, int parent){
        for (auto c : graph[root]){
            if( c != parent){
                sum[c] = sum[root] - count[c] + N - count[c];
                dfs2(graph,c,root);
            }
        }
    }    
};