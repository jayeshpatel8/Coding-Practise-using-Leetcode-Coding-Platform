class Solution {
public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> G(n);
        for (auto &e : edges){
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
        }   
        vector<int> deg(n),leaf(price),root(price);
        queue<int> q;
        for (auto i=0; i<n; i++){
            deg[i]=G[i].size();
            if (deg[i]==1){
                root[i]=0;
                q.push(i);
            }
        }
        long long ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while (sz--){
                int u = q.front(); q.pop();
                deg[u]--;
                for (auto v : G[u]){
                    if (deg[v]  ){
                        ans = max({ans, (long long)root[u]+leaf[v],  (long long)root[v] + leaf[u]});
                        root[v] = max(root[v], root[u]+ price[v]);
                        leaf[v] = max(leaf[v], leaf[u]+ price[v]);
                    }
                    if (deg[v]-- == 2) q.push(v);
                }
            }
        }
        return ans;
    }
};