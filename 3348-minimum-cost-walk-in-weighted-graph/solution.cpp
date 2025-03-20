class Solution {
public:
    vector<int> uf,sz, and_;
    int find(int a){
        if (uf[a] < 0) return a;
        return uf[a] =find(uf[a]);
    }
    void merge( int a,  int b, int w){
        int pa=find(a),pb=find(b);
        
        if (pa==pb) return;
        if (sz[pa]  <= sz[pb]){
            uf[pa]=pb;
            sz[pb] +=sz[pa];
          //  and_[pb] &=and_[pa] & w;
        }
        else{
            uf[pb]=pa;
            sz[pa] +=sz[pb];
           // and_[pa] &=and_[pb]& w;
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        uf.resize(n,-1);
        sz.resize(n,1);
        and_.resize(n, -1);
        for (auto &e :  edges){
            merge(e[0],e[1],e[3]);
        }
        for (auto &e :  edges){
            int p = find(e[0]);
            and_[p] &= e[2];
        }
        vector<int> ans;
        for (auto& q: query){
            int pa= find(q[0]), pb=find(q[1]);
            if (pa !=pb) ans.push_back(-1);
            else ans.push_back(and_[pa]);
        }
        return ans;
    }
};
