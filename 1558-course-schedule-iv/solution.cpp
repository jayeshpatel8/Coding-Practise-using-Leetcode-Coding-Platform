class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<vector<int>> g(n, vector<int>());
        for (auto& e : pre){
            g[e[0]].push_back(e[1]);
        }
        auto dfs = [&](auto & start, auto & target){
            vector<bool> vis(n,false);
            vis[start]=true;
            vector<int> q{start};
            while (!q.empty()){
                vector<int> t;
                for (auto u : q){                    
                    for (auto v: g[u]){
                        if (vis[v]) continue;
                         if (v == target) return true;
                        vis[v]=true;
                        t.push_back(v);
                    }
                }
                q.swap(t);
            }
            return false;
        };
        vector<bool> ans;
        for(auto& q : queries){
            ans.push_back(dfs(q[0],q[1]));
        }

        return ans;
    }
};
