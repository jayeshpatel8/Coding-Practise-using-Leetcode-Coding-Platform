class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<unordered_set<string>>> M;
        for ( auto v : accounts){
            string name = v[0];
            int merged = 0;
            vector<int> m;
            if (M.count(name)){
                for (int i=0; i<M[name].size(); i++){
                    for (int j=1; j<v.size(); j++){
                        if (M[name][i].count(v[j])){
                            // merge
                            //i.insert(v.begin()+1,v.end());
                            m.push_back(i);
                            merged=1;
                            break;
                        }
                    }
                }
            }
            if (merged)
            {
                for (int i=1; i<m.size(); i++){
                    M[name][m[0]].insert(M[name][m[i]].begin(),M[name][m[i]].end());
                    M[name][m[i]].clear();
                }
                M[name][m[0]].insert(v.begin()+1,v.end());
            }
            else{
                unordered_set<string> email(v.begin()+1,v.end());
                M[name].push_back(email);
            }
        }
        vector<vector<string>> ans;
        for ( auto [n,e] : M){
            for ( auto i : e){
                if (i.empty()) continue;
                vector<string> s {n};
                for (auto j : i)
                    s.push_back(j);
                sort(s.begin()+1,s.end());
                ans.push_back(s);
            }
        }
        return ans;
    }
};