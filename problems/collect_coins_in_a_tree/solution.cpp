class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        vector<vector<int>> G(n);
        vector<int> len(n,3e4), deg(n);
        for (auto &e : edges){
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
            deg[e[0]]++;deg[e[1]]++;
        }
        queue<int> q;
        
        for (int i=0;i<n;  i++)
            if (deg[i]==1)
                q.push(i);
  
        while (!q.empty()){
            int u = q.front(); q.pop();
            if (--len[u] > 0){
                n--;
                for (auto v : G[u]){
                    len[v] = min<int>({ len[v] , len[u] , coins[u]? 2: (int)3e4});
                    if (--deg[v]==1) 
                        q.push(v);
                }
            }
        }
        return 2*max(0,n-1);
    }
};