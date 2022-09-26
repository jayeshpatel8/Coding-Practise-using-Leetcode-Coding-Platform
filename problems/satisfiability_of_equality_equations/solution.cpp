class Solution {
public:
    vector<int> uf,sz;
    
    int find(int i){
        return uf[i] < 0 ? i : (uf[i]=find(uf[i]));
    }
    void merge(int a, int b){
        int pa = find(a), pb = find(b);
        if (pa==pb) return;
        if (sz[pa] < sz[pb])
            uf[pa]=pb, sz[pb]+=sz[pa];
        else
            uf[pb]=pa, sz[pa]+=sz[pb];
    }
    bool equationsPossible(vector<string>& equations) {
        uf.resize(26,-1);
        sz.resize(26,1);
        for (auto &e : equations){
            if (e[1] == '=')
                merge(e[0]-'a',e[3]-'a');
        }
        for (auto &e : equations){
            if (e[1] == '!'){
                if (find(e[0]-'a') == find(e[3]-'a')) return false;
            }
        }
        return true;
    }
};