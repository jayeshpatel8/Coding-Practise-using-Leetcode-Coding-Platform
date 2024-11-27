class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> G(n);
        vector<int> ans, dist(n);
        for (int i=1; i<n; i++)
            G[i-1].push_back(i),dist[i]=i;
        for (auto qe : queries){
            int a = qe[0], b = qe[1];
            G[a].push_back(b);

         auto d = dist[b];
            for (int u=a; u<n; u++){
                for (auto v : G[u]){
                    dist[v] = min(dist[v], dist[u] + 1);
                }
                if ( u==a && dist[b] == d) break;
            }
            ans.push_back(dist[n-1]);
        }
        return ans;
    }
};
