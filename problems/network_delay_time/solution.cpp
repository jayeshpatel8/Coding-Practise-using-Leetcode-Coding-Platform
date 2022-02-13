class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<array<int,2>> G[n+1];
        for (auto & t : times){
            G[t[0]].push_back({t[1],t[2]});
        }
        priority_queue<array<int,2> ,vector<array<int,2>>, greater<>> pq;
        pq.push({0,k});
        vector<int> vis(n+1, INT_MAX);
        vis[0]=-1;
        while (!pq.empty()){
            auto u1 = pq.top(); pq.pop();
            int u = u1[1], time= u1[0];
            if (time > vis[u]) continue;
            vis[u]=time;
            
            for (auto v : G[u]){
                if (vis[v[0]] > time+v[1]){
                    vis[v[0]] = time+v[1];
                    pq.push({vis[v[0]],v[0]});
                }
            }
        }
        int ans=-1;
        for (auto t : vis) {ans = max(ans, t);
                           }
        return ans == INT_MAX ? -1 : ans;
    }
};