class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n+1);
        vector<vector<int>> G(n+1);
        vector<int> dis(n+1,INT_MAX);
        for (auto &e : roads){
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
            dis[e[0]] =  min (dis[e[0]],e[2]);
            dis[e[1]] =  min (dis[e[1]],e[2]);
        }
        
        queue<int> q;
        q.push(1);
        vis[1]=true;
        int ans = dis[1];
        while(!q.empty()){
            auto u = q.front(); q.pop();
            ans= min(ans,dis[u]);
            for (auto j : G[u]){
                if (vis[j]) continue;
                vis[j]=true;
                q.push(j);
            }
        }
       return ans; 
    }
};