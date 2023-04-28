class Solution {
public:
    vector<int> uf,sz;
    int find ( int i){
        return uf[i] <0 ? i : uf[i] = find(uf[i]);
    }
    void join (int a, int b){
        int pa= find(a), pb= find(b);
        if (pa != pb){
            if (sz[pa] < sz[pb])
                uf[pa]=pb, sz[pb] += sz[pa];               
            else
                uf[pb]=pa, sz[pa] += sz[pb];   
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        uf.resize(strs.size(),-1);
        sz.resize(strs.size());
        for (int i=0; i<strs.size(); i++)
            for (int j=i+1; j<strs.size(); j++){
                if (similar(strs[i],strs[j])){
                    join(i,j);
                }
            }
        return count(begin(uf),end(uf),-1);
    }
    bool similar(string &a, string &b){
        for (int i=0,cnt=0; i<a.size(); i++){
            if (a[i] != b[i] && ++cnt >2) return false;
        }
        return true;
    }
};