class Solution {
public:
    
    vector<int> uf;
    vector<int> size;
    int makeConnected(int n, vector<vector<int>>& conn) {
        uf.resize(n,-1);
        size.resize(n);
        int unused = 0;
        vector<int> vis(n);
        for (int i=0; i<conn.size(); i++){
            int u=conn[i][0], v= conn[i][1];
            if (isconn(u,v)){
                unused++;
            }
            else{
                connect(u,v);
            }
        }
        int cnode=0;
        for (int i=1; i<n; i++){
            if (!isconn(0,i)){
                if (unused){
                    connect(0,i);
                    cnode++;
                    unused--;
                }
                else return -1;
            }
        }
        
        return cnode;
    }
    bool isconn(int u, int v){
        return find(u) == find(v);
    }
    int find(int i){
        return uf[i] < 0 ? i : uf[i] = find(uf[i]);
    }
    void connect(int u, int v){
        int pu = find(u), pv=find(v);
        if (pu != pv){
            if (size[pu] < size[pv]){
                uf[pu]=pv;
                size[pv]+=size[pu];
            }
            else{
                uf[pv]=pu;
                size[pu]+=size[pv];
            }
        }
    }
};