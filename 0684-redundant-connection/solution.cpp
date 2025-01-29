class Solution {
public:
    vector<int> uf,uf_size;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        uf.resize(n+1,-1);
        uf_size.resize(n+1,1);
        for (int i=0; i<=n; i++) uf[i]=i;
        for (auto &e : edges){
            if (find(e[0]) == find(e[1])) return e;
            connect(e[0],e[1]);
        }
        return {0,0};
    }
    int find(int i){
        return uf[i] = (uf[i]==i? i : find(uf[i]));
    }
    void connect(int a, int b){
        int pa=find(a), pb=find(b);
        if (pa == pb) return;
        if (uf_size[pa] < uf_size[pb]){
            uf_size[pb] +=uf_size[pa];
            uf[pa]=pb;
        }
        else{
            uf_size[pa] +=uf_size[pb];
            uf[pb]=pa;
        }
    }
};
