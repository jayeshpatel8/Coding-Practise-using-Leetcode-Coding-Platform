class Solution {
public:
    vector<int> uf,sz;
    int find(int i){
        return uf[i]<0? i : uf[i] =find(uf[i]);
    }
    void join(int i, int j){
        int pi = find(i), pj = find(j);

        if (pi != pj){
            if (sz[pi] < sz[pj])
                uf[pi]=pj, sz[pj]+=sz[pi];
            else
                uf[pj]=pi, sz[pi]+=sz[pj];
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        uf.resize(n,-1);
        sz.resize(n);
        sort(begin(edgeList), end(edgeList),[&](auto &a, auto &b){
            return a[2] < b[2];
        });
        
        vector<bool> ans(queries.size());
        for (int i=0; i<queries.size(); i++) queries[i].push_back(i);
        sort(begin(queries), end(queries),[&](auto &a, auto &b){
            return a[2] < b[2];
        });
        int e=0;
        for (auto q  : queries){
            for (; e < edgeList.size() && edgeList[e][2] < q[2]; e++)
                join(edgeList[e][0],edgeList[e][1]);

            ans[q[3]]=(find(q[0]) == find(q[1]));
                
        }
        return ans;
    }
};