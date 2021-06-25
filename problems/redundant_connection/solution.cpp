class Solution {
public:
    vector<int>  uf;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        uf.resize(n+1);
        for ( int i=1; i<=n; i++) uf[i]=i;
        
        for (auto &e : edges){
            int u =e[0], v = e[1];
            if (find(u) == find (v)) return e;
            union_(u,v);
        }
        return edges[0];
    }
    int find(int n){
        if (n == uf[n]) return n;
        return uf[n] = find(uf[n]); 
    }
    void union_(int u, int v){
        int up = find(u), vp= find(v);
        if (up == vp)
            return;
        
         {
            uf[vp] = up;
        }

    }
};