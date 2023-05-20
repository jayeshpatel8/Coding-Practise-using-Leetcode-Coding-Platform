class Solution {
public:
unordered_map<string,vector<pair<string,double>>> G;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        for (auto i=0; i< equations.size(); i++){
            auto &e = equations[i];
            G[e[0]].push_back({e[1], values[i]});
            G[e[1]].push_back({e[0], 1/values[i]});
        }
        vector<double> ret;
        for ( auto &q : queries){
            unordered_set<string> vis;
            if (G[q[0]].size()==0 ||G[q[1]].size()==0 )
                ret.push_back(-1.0);
            else
                ret.push_back(dfs(q[0],q[1],vis));
        }
        return ret;
    }
    double dfs(string u , string t, unordered_set<string> vis){
        if (u==t ) return G[u].size() ? 1.0 : -1.0;
        auto ret = -1.0;
        for (auto [v,d] : G[u]){
            if (vis.count(u+v)) continue;
            vis.insert(u+v);
            auto r = dfs(v,t,vis);
            if (r != -1.0) return d * r;
        }
        return ret;
    }
};