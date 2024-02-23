class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,1e7);
         vector<vector<array<int,2>>> G(n);
         for (auto &f : flights)
            G[f[0]].push_back({f[1], f[2]});
        queue<array<int,2>>q;
        q.push({src, 0});
        while (!q.empty() && k >= 0){
            k--;
            int sz = q.size();
            while (sz-- > 0){
                auto from = q.front(); q.pop();
                for (auto &to : G[from[0]]){
                    if ( from[1] + to[1] < dist[to[0]]){
                        dist[to[0]] = from[1] + to[1];
                        q.push({to[0],dist[to[0]]});
                    }
                }
            }
        }
        return dist[dst] == (int)1e7 ? -1 : dist[dst];
    }
};
