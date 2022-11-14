class Solution {
public:
    vector<int> uf,sz;
    int cnt=  0;
    int find(int i){
        if ( uf[i] < 0 ) {
 
            return i;
        }
        else{
         return uf[i] = find(uf[i]);
        }
    }
    void merge (int i, int j){
        auto pa = find(i), pj = find(j);
        if (pa== pj) return;
        if (sz[pa]>sz[pj]){
            uf[pa] = pj;
            sz[pj] += sz[pa];            
        }
        else
            uf[pj]=pa, sz[pa]+=sz[pj];
  
    }
    int removeStones(vector<vector<int>>& stones) {
        uf.resize(10001*2, - 1);
        sz.resize(10001*2,1);
        for (auto & st : stones){
            merge(st[0], st[1]+10001);
        }
        set<int> vis;
        int ans = 0;
        for (auto & st : stones){
            if (vis.count(find(st[0]))) continue;
            ans ++;
            vis.insert(find(st[0]));
        }
        return stones.size() - ans ;
    }
};