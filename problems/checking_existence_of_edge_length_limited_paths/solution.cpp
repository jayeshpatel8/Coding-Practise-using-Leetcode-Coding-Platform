class uf{
    vector<int> id,sz;
    public:
    uf(int n) : id(n),sz(n){
        iota(id.begin(), id.end(), 0);
        iota(sz.begin(), sz.end(), 0);
    }
    int find(int a){
        return (id[a]==a) ? a : id[a] = find(id[a]);
    }
    void unionf(int a, int b){
        int x= find(a), y =find(b);
        if (x==y) return;
        if (sz[x] < sz[y])
        { id[x]=y; sz[y] +=sz[x];}
        else{
            id[y]=x; sz[x] +=sz[y];
        }
    }
    bool connected(int a, int b){
        return find(a) == find(b);
    }
};
const int N = 1e5 +1;
struct Node {
    int u, v, dis, idx;
    bool operator<(const Node& b) {
        return dis < b.dis;
    }
} e[N], q[N];
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        vector<bool> res(queries.size());
//        for (int i = 0; i < queries.size(); i++){
  //          queries[i].push_back(i);
    //    }
      //  sort(edgeList.begin(), edgeList.end(), [&](auto &a, auto &b){ return a[2] < b[2]; });
        //sort(queries.begin(), queries.end(), [&](auto &a, auto &b){ return a[2] < b[2]; });
        
        int i=0;
        for (auto ed : edgeList) e[i++]={ed[0],ed[1],ed[2]};
         i=0;for (auto qu : queries) q[i++]={qu[0],qu[1],qu[2],i};
        sort(e,e+edgeList.size());
        sort(q,q+queries.size());
        i=0;
        int j=0;
        uf u(n);
        for (;j<queries.size();j++){
            for (;   i< edgeList.size() && e[i].dis <q[j].dis ; i++){
                u.unionf(e[i].u, e[i].v);
            }
            res[q[j].idx] = u.find(q[j].u) == u.find(q[j].v);
        }

        return res;
    }

};