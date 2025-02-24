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
};
