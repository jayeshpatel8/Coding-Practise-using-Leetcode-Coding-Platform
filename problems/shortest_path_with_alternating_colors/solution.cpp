class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<array<int,2>>> graph(n);
        for (auto &e : redEdges){
            graph[e[0]].push_back({e[1],0});
        }
        for (auto &e : blueEdges){
            graph[e[0]].push_back({e[1],1});
        }
        vector<int> ans(n,-1);
        vector<vector<bool>> vis(n,vector<bool>(2));
        queue<array<int,2>> q;
        int dist=1; 
        for (auto e : graph[0])
            q.push({e[0],e[1]});
        vis[0][0]=vis[0][1]=1; ans[0]=0;
        while( !q.empty() ){
            int sz = q.size();
            while (sz-- > 0){
                auto e = q.front(); q.pop();
                if (vis[e[0]][e[1]]) continue;
                vis[e[0]][e[1]]=1;
                if (ans[e[0]] == -1)
                    ans[e[0]] = dist;
                for (auto i : graph[e[0]]){
                    if (i[1] == e[1] || vis[i[0]][i[1]]) continue;
                    q.push({i[0],i[1]});
                }
            }
            dist++;
        }
        return ans;
    }
    
};