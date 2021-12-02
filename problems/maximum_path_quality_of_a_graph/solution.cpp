class Solution {
public:
    int ans = 0;
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        vector<vector<pair<int,int>>> g(values.size());
        vector<int> vis(values.size());
        
        for (auto e : edges)
        {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        
        dfs(values,g,maxTime,vis,0);
        return ans;
    }
    void dfs (vector<int>& v, vector<vector<pair<int,int>>>& g, int time, vector<int> & vis, int i,int cur = 0) {
        
        int val = vis[i]++ ==0 ? v[i] : 0;
        
        if (i==0) ans = max(ans, val + cur);
        
        for ( auto e : g[i]){
            if ( e.second <= time)
                dfs(v,g,time-e.second,vis,e.first,cur+val);
        }
        vis[i]--;
    }
};