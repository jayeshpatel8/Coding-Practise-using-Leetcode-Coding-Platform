
        class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> G(n+1);
        for (auto &e : edges)
            G[e[0]-1].push_back(e[1]-1),G[e[1]-1].push_back(e[0]-1);
            
        vector<int> seen(n+1); 
        vector<vector<int>> cc;
        auto bfs2 = [&](int x) {
            cc.push_back({x});         
            seen[x] = 1; 
            queue<int> q; q.push(x); 
            for (; q.size();) 
                for (int sz = q.size(); sz; --sz) {
                    auto u = q.front(); q.pop(); 
                    
                    for (auto& v : G[u]) 
                        if (!seen[v]) {
                            seen[v] = seen[u]+1; 
                            q.push(v); 
                            cc.back().push_back(v);
                        }
                        else if ((seen[v]&1) == (seen[u]&1)){
                            return -1;   
                        }
                }
            return 0; 
        };      
        auto bfs = [&](int x) {
            int ans = 0; 
            vector<bool> seen(n+1); 
            seen[x] = true; 
            queue<int> q; q.push(x); 
            for (; q.size(); ++ans) 
                for (int sz = q.size(); sz; --sz) {
                    auto u = q.front(); q.pop(); 
                    for (auto& v : G[u]) 
                        if (!seen[v]) {
                            seen[v] = true; 
                            q.push(v); 
                        }
                }
            return ans; 
        }; 
        
        for (auto i = 0; i<n; i++){
            if (!seen[i])
                if (bfs2(i)) return -1;
        }
        int ans2 = 0; 
        for (auto& g : cc) {
            transform(g.begin(), g.end(), g.begin(), bfs); 
            ans2 += *max_element(g.begin(), g.end()); 
        }        
        return  ans2;
    }
};