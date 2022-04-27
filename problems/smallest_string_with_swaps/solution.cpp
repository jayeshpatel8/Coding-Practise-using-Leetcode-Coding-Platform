class Solution {
public:
    vector<int> uf ,size;
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        uf.resize(n,-1);
        size.resize(n);
        
        for (auto &p : pairs)
            join(p[0],p[1]);
        
        unordered_map<int,vector<int>> idx,val;
        for (int i=0; i<n; i++){
            int pi =  find(i);
            idx[pi].push_back(i);
            val[pi].push_back(s[i]);            
        }            
        for (auto & [i, index] : idx ){
            sort(begin(index),end(index));
            auto vv = val[i];
            sort(begin(vv),end(vv));
            for (int j = 0; j<index.size(); j++)
                s[index[j]] = vv[j];            
        }
        return s;
    }
    int find(int i){
        return uf[i] == -1 ? i : (uf[i] = find (uf[i]));
    }
    void join(int i, int j){
        auto pi = find(i) , pj = find (j);
        if (pi != pj){
            if (size[pi] < size[pj])
                uf[pj] = pi, size[pi] += size[pj];
            else
                uf[pi] = pj, size[pj] += size[pi];
        }
    }
};