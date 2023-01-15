class Solution {
public:
int ans {0};
    vector<int> uf,sz;
    int find(int a) {
        return uf[a]<0 ?a : uf[a] = find(uf[a]);
    }
    void join(int a,int b){
        auto pa = find(a), pb = find (b);
        if (pa != pb){
            if (sz[pa] >= sz[pb])
                sz[pb] += sz[pa], uf[pa]=pb;
            else
                sz[pa] += sz[pb], uf[pb]=pa;
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
         int N = vals.size();
         uf.resize(N,-1), sz.resize(N);
        vector<vector<int>> G(N);
        map<int,vector<int>> nodes;
        for (int i=0; i<N; i++)
            nodes[vals[i]].push_back(i);        
        for (auto &e : edges){
            int a =e[0] ,b  = e[1];
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);        
        }
       
        for ( auto &[val,n] : nodes){

            for (auto u : n){
                for (auto v : G[u]){
                    if (vals[u] >= vals[v])
                        join(u, v);
                }
            }
             
            unordered_map<int,int> connected;
            for (auto u : n) {
                connected[find(u)]++;
            }
            int cnt = 0;
            for (auto &[v,c] : connected)  {
                ans = ans + (c * (c+1)/2);
            }
        }
        return ans;
    }

};