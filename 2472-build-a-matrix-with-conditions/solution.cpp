class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        auto r = topo(k,row), c = topo(k,col);

        if (r.empty()|| c.empty()) return {};
        vector<vector<int>> ans(k,vector<int>(k));
        for (int i=1; i<=k; i++){
            ans[r[i-1]][c[i-1]]=i;
        }
        return ans;
    }
    vector<int> topo(int k, vector<vector<int>>& con){
        vector<int> deg(k+1), q, sorted,id(k);
        vector<unordered_set<int>> G(k+1);
        for (auto &c : con){
            if (G[c[0]].insert(c[1]).second)
                deg[c[1]]++;
        }
        for (auto d=1; d<=k; d++)
            if (deg[d] == 0) q.push_back(d);

        while (!q.empty()){
            vector<int> t;
            for (auto u : q){
                sorted.push_back(u);
                for (auto v : G[u])
                    if (--deg[v]==0)
                        t.push_back(v);
            }
            q.swap(t);
        }
        if (sorted.size() != k)return {};
        iota(begin(id),end(id),0);
        sort(begin(id),end(id),[&](int a , int b){ return sorted[a] < sorted [b];});
        return id;
    }
};

// 0 2 1
// 2 1 0
