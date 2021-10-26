class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& rel, vector<int>& time) {
        vector<vector<int>> G(n+1);
        vector<int> indeg(n+1), D(n+1);
        for (auto  e : rel ) G[e[0]].push_back(e[1]), indeg[e[1]]++;
        queue<int> q;
        for (int i=1; i<=n; i++) 
            if (indeg[i]==0) 
                q.push(i), D[i]=time[i-1];
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            for (auto v : G[u]){
                D[v] = max(D[u]+time[v-1], D[v]);
                if (--indeg[v]==0)
                    q.push(v);
            }
        }
        return *max_element(begin(D), end(D));
    }
};