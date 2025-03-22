class Solution {
public:
    vector<int> uf, sz;
    int find(int n){
        if (uf[n] < 0) return n;
        return uf[n] = find(uf[n]);
    }
    void merge(int a , int b){
        int pa =find(a), pb= find(b);
        if (pb == pa) return ;
        if (sz[pa] <= sz[pb])
            uf[pa]=pb, sz[pb]+=sz[pa];
        else 
            uf[pb]=pa, sz[pa]+=sz[pb];        
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        uf.resize(n,-1);
        sz.resize(n,1);
        unordered_map<int,int> ec;
        for (auto& e : edges){
            merge(e[0],e[1]);
           
        }
        for (auto& e : edges)
            ec[find(e[0])]++;
        int ans=0;
        for (int v=0; v<n; v++){
            if (find(v) == v){
                int c =  sz[v];
                int nc = (c * (c-1))/2;
                if (ec[v] == nc) ans++;
            }
        }
        return ans;
    }
};
