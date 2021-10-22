class Solution {
public:
    int vis[100000]={};
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& pat) {
        vector<int> G[pat.size()];
        for (auto i : edges)
        {
            G[i[0]].push_back(i[1]);
            G[i[1]].push_back(i[0]);
        }
        int d = 1, res= 0;
        queue<int> q; q.push(0);vis[0]=1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front(); q.pop();
               
                for ( auto v : G[u]){
                    if (vis[v]) continue;
                    q.push(v);
                     vis[v]=1;
                    res= max(res, d*2 + (d*2-1) /pat[v] * pat[v] );
                }
            }
            d++;            
        }
        return res+1;
    }
};