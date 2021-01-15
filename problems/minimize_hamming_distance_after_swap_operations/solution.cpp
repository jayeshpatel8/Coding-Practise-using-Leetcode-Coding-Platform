class Solution {
public:
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
            int sz = source.size();
            vector<int> uf(sz, -1);
                    
        for (auto s : allowedSwaps)
            unionf(uf,s[0],s[1]);        
        vector<unordered_multiset<int>> M(sz);
        for (int i=0; i<source.size(); i++){
            if (source[i] != target[i]  )
                M[find(uf,i)].insert(source[i]);
        }
        int hdist=0;
        for (int i=0; i<source.size(); i++){
            if (source[i] != target[i]  ) {                
                auto &unionset = M[find(uf,i)];
                auto it = unionset.find(target[i]);
                if ( it == unionset.end() ) {hdist++; }
                else
                    unionset.erase(it);                             
            }
        }
        return hdist;
    }
    int find(vector<int> &uf,int idx){
        if ( uf[idx] < 0) return idx;
        return uf[idx] = find(uf,uf[idx]);
    }
    void unionf(vector<int>& uf, int i, int j){
        int pi= find(uf,i);
        int pj = find(uf,j);
        if (pi != pj) {
            if (uf[pi] > uf[pj])
                swap(pi, pj);
            uf[pi] += uf[pj];
            uf[pj] = pi;
        }
        
    }
};