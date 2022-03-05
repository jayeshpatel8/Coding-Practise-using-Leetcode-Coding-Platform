class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> in(n);
        vector<vector<int>> g(n);
        for (auto &e : edges){
            int u = e[0] ,v =e[1];
            in[v]++;
            g[u].push_back(v);
        }
        queue<int> q;
        vector<vector<bool>> f(n,vector<bool>(n));
        vector<vector<int>> ans(n);
        for (int i=0;i<in.size(); i++){
            if (in[i] ==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            for (auto &v : g[u]){
                ans[v].push_back(u);
                f[v][u]=1;
                for (auto &v1 : ans[u]){
                    if (f[v][v1] == 0){
                     ans[v].push_back(v1);
                        f[v][v1]=1;
                    }
                }
                if (--in[v] == 0){
                    q.push(v);
                }
            }
        }
        for (auto & i : ans){
            sort(begin(i),end(i));
        }
        return ans;
    }
};