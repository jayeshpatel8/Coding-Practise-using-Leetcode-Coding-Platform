class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        int vis[100][2]={};
        vector<vector<array<int,2>>> G(n);
        for (auto &e : redEdges)
            G[e[0]].push_back({e[1],0});
        for (auto &e : blueEdges)
            G[e[0]].push_back({e[1],1});
        queue<array<int,2>> q;
        q.push({0,2});
        int cnt=0;
        vector<int> ans(n,-1);
        ans[0]=0;
        vis[0][0]=vis[0][1]=1;
        while (!q.empty()){
            int sz= q.size();
            while (sz-- > 0){
                auto cur = q.front(); q.pop();
                if (ans[cur[0]]==-1)
                    ans[cur[0]]=cnt;                
                for (auto &v : G[cur[0]]){
                    if (vis[v[0]][v[1]] || v[1] == cur[1]) continue;
                    
                        vis[v[0]][v[1]]=1;
                        q.push(v);
                    
                }
            }
            cnt++;
        }
        return ans;
    }
};