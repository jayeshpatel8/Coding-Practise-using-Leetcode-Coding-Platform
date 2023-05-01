class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& roads) {
        int N = roads.size();
        vector<int> dist(N,INT_MAX);
        queue<array<int,2>> q;
        for (auto i=0; i< roads.size(); i++){
            auto &r = roads[i];
            dist[i] =  abs(r[0]-start[0]) + abs(r[1]-start[1]) + r[4];
            q.push({dist[i],i});
        }

        int ans =  abs(target[0]-start[0]) + abs(target[1]-start[1]);
        while (!q.empty()){
            auto [d , u] = q.front(); q.pop();

            if (dist[u]  != d) continue;

            ans= min(ans, dist[u]  + abs(target[0]-roads[u][2]) + abs(target[1]-roads[u][3]));

            for (int v=0; v<roads.size(); v++){
                auto &r = roads[v];
                int w =   abs(roads[u][2]-r[0]) + abs(roads[u][3]-r[1]) + r[4];
                if (dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    q.push({dist[v],v});
                }
            }
        }
        return ans;
    }
};