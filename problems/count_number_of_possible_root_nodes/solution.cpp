#if 1
class Solution {
public:
    int correct=0,ans=0,K;
    map<pair<int,int>,int> ust;
    vector<bool> vis;
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size()+1;
        vis.resize(n);
        vector<vector<int>> G(n);
        for (auto &e : edges)
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        
        for (auto &g : guesses) ust[{g[0] , g[1]}]=1;
        K=k;
        dfs1(G);

        fill(begin(vis),end(vis),0);
        dfs2(G,0,correct);
        return ans;
    }
    void dfs1(vector<vector<int>> & G,int c = 0){

        vis[c]=1;
        for ( auto n :  G[c]){
            if (vis[n]) continue;
            if (ust.count({c, n}))
                correct++;
            dfs1(G,n);
        }
    }
    void dfs2(vector<vector<int>> & G,int c ,int a1 ){

        vis[c]=1;
        if (a1 >= K) ans++;
        for ( auto n :  G[c]){
            if (vis[n]) continue;

            dfs2(G,n,a1 - ust[{c,n}] + ust[{n,c}]);
        }
    }    
};
#endif
