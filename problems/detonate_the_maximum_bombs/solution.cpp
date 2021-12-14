class Solution {
public:
   // int vis[101]={};
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> g(bombs.size());
        for (int i =0; i<bombs.size(); i++){
            long x = bombs[i][0], y = bombs[i][1], r = (long)bombs[i][2] *bombs[i][2];
            for (int  j=0; j<bombs.size(); j++){
                if (i==j) continue;
                long x1 = x-bombs[j][0], y1 = y-bombs[j][1];
                if ((x1)*(x1)  + (y1)*(y1) <= r )
                    g[i].push_back(j);
            }
        }
        int ans = 0;
        for (int i =0; i<bombs.size(); i++){
            vector<int> vis(bombs.size(),0);
            ans = max(ans, dfs(g,i, vis));
        }
        return ans;
    }
    int dfs(vector<vector<int>>& g,int i, vector<int>& vis){
        int ans=0;
        if (!vis[i]){
            vis[i]=1;
            for(auto j : g[i])
                if (!vis[j])
                    vis[i] += dfs(g,j,vis);
        }
        return vis[i];
    }
};