class Solution {
public:
    unordered_map<int,vector<int>> g;

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        for (auto p : adjacentPairs){
            if (g.count(p[0])==0) g[p[0]]=vector<int>();
            if (g.count(p[1])==0) g[p[1]]=vector<int>();
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);            

        }
        vector<int> res(g.size());
        
        for (auto [i,v] : g){
            if (v.size()==1){
                res[0]=i;
                res[1]=v[0];                
                break;
            }
        }
        for (int i=2; i<g.size(); i++){
            vector<int>& v = g[res[i-1]];
            if (v[0]!=  res[i-2]){
                    res[i]  = v[0];
            }
            else
                res[i]  = v[1];
            
        }
        
        return res;
    }

};