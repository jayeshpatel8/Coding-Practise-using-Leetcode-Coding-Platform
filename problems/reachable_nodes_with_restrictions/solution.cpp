class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<bool> vis(n);
        vector<vector<int>> G(n);
        
        for (auto i : restricted)vis[i]=true; 
        for (auto &e : edges)
            if (!vis[e[0]] && !vis[e[1]])
                G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
        vector<int> q{0};vis[0]=true;
        int ans = 0;
        while (!q.empty()){
            vector<int> t;
            for (auto i  : q){            
                ans++;
                for (auto v : G[i]){
                    if (vis[v] ) continue;
                    vis[v]=true;
                    t.push_back(v);
                }
            }
            q.swap(t);
        }
        return ans;
    }
};