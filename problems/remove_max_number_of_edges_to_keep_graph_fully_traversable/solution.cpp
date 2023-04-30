class Solution {
public:
    vector<int> uf[2],sz[2];
    int find (int id, int i){
        return uf[id][i] < 0 ? i : uf[id][i] = find (id,uf[id][i]);
    }
    int connect(int id, int i, int j){
        int pi = find(id,i), pj = find (id,j);
        if (pi==pj) return 1;
        if (sz[id][pi] < sz[id][pj])
            uf[id][pi]=pj, sz[id][pj] += sz[id][pi];
        else
            uf[id][pj]=pi, sz[id][pi] += sz[id][pj];
        return 0;
    }
    bool connect(vector<int> &e){
        int i=e[1], j = e[2];
        
        if (e[0]==3)
           return connect(0,i,j) || connect(1,i,j);
        else if (e[0]==2)
            return connect(1,i,j);
        else
            return connect(0,i,j);
        return 0;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        uf[0].resize(n+1,-1),uf[1].resize(n+1,-1);
        sz[0].resize(n+1),sz[1].resize(n+1);
        int rem=0;
        for (auto &e : edges)
            if (e[0]==3)  
                rem += connect(e);
        for (auto &e : edges)
            if (e[0]!=3)  
                rem += connect(e);

        return (count(begin(uf[0]),end(uf[0]),-1) != 2) || (count(begin(uf[1]),end(uf[1]),-1)!=2) ? -1 : rem;
    }
};