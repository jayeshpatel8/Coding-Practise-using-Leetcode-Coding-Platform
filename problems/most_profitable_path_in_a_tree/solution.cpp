class Solution {
public:
int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int  N = edges.size()+1;
        vector<vector<int>> G(N);
        for (auto &e : edges)
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);

        function<array<int,2>(int,int,int)> dfs = [&](int u, int p, int dist)->array<int,2>{ 
            int ans= INT_MIN, open =  u==bob ? dist+1 : 0;

            for (auto v : G[u]){
                if (v==p) continue;
                auto a =  dfs(v,u,dist+1);
                ans = max(ans, a[0]);
                open = max(open, a[1]);
            }
            if (open) amount[u] = open==1 ?  amount[u]/2 : 0;
            return { amount[u] + (ans==INT_MIN ? 0 : ans), open-2};
        };
        return dfs(0,-1,0)[0];
}
    int mostProfitablePath2(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int  N = edges.size()+1;
        vector<vector<int>> G(N);
        for (auto &e : edges)
            G[e[0]].push_back(e[1]), G[e[1]].push_back(e[0]);
       
        vector<int> vis(N,INT_MAX),vis2(N);
        dfs(G,vis,bob,0);
        vector<array<int,2>> q{{0,amount[0]}};
        int t=1, ans = INT_MIN;
        vis2[0]=true;

        while (!q.empty()){
            vector<array<int,2>> q2;
            ++t;
            for (auto &u : q){
                bool leaf=true;
                for (auto v : G[u[0]]){
                    if (vis2[v]) continue;
                    leaf=false;
                    vis2[v]=true;
                    if (t>vis[v]) 
                        q2.push_back({v,u[1]});
                    else if (t==vis[v])
                        q2.push_back({v,u[1] + amount[v]/2});
                    else
                        q2.push_back({v,u[1] + amount[v]});
                }
                if (leaf)
                    ans= max(ans, u[1]);                
            }
            q.swap(q2);
        }
        return ans;
    }
    bool dfs(vector<vector<int>> &G, vector<int> & vis, int u, int t){
        bool found=false;
        vis[u]=++t;
        if (u==0) return true;
        for (auto &v : G[u]){
            if (vis[v] != INT_MAX) continue;            
            found |= dfs(G,vis,v,t);
            if (found)break;
        }
        if (!found) vis[u]= INT_MAX;
        return found;
    }
};