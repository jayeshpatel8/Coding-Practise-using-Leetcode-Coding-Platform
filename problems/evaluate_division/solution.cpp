class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equa, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> g;
        int i=0;
        for (auto &e : equa){
            g[e[0]].push_back({e[1],values[i]});
            g[e[1]].push_back({e[0],1.0/values[i++]});
        }
        auto bfs = [&](string u, string v){
            unordered_set<string> vis;
            queue<pair<string, double>> q;
            q.push({u,1});
            vis.insert(u);
            
            while (!q.empty()){
                int sz = q.size();
                while (sz-- > 0){
                    auto i = q.front(); q.pop();
                    auto u1 = i.first;
                    auto c1 = i.second;
                    if (u1 == v) return c1;
                    for (auto &j : g[u1]){
                        if (vis.count(j.first) == 0){
                            vis.insert(j.first);
                            q.push({j.first,c1 * j.second});
                        }
                    }
                }
            }
            return -1.0;
        };
        vector<double> ans;
        for (auto &q : queries){
            if ( g.count(q[0]) == 0 || g.count(q[1]) == 0 )
                ans.push_back(-1);
            else{
                ans.push_back(bfs(q[0],q[1]));
            }
        }
        return ans;
    }
};