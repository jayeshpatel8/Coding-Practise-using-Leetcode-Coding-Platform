class Solution {
public:
vector<int> sum,count;
int N;
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        // first: count total nodes at each nodes using count[n]
        // second:  sum[node]= sum[root] - (no_of_subnodes_at_this_node) + (remainming_sub_nodes = N-no_of_subnodes_at_this_node);
        sum.resize(n,0);
        count.resize(n,1);
        N=n;
        vector<vector<int>> G(n);
        for ( auto  &e : edges){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        dfs(G,0,-1);
        dfs2(G,0,-1);
        return sum;
    }
    void dfs(vector<vector<int>>& G,int root, int par){
        for (auto node : G[root]){
            if (node == par) continue;
            dfs(G,node,root);
            sum[root] += sum[node] + count[node];
            count[root] += count[node];
        }
    }
    void dfs2(vector<vector<int>>& G,int root, int par){
        for (auto node : G[root]){            
            if (node == par) continue;
            sum[node] = sum[root] -count[node]+ (N-count[node]);
            dfs2(G,node,root);            
        }
    }     
};
