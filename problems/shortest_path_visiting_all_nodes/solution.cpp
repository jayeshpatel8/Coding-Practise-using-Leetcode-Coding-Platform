class Solution {
public:
    vector<vector<int>> dp;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n= graph.size();
        dp.resize(n,vector<int>(1<<n,INT_MAX) );
        queue<pair<int,int>> q; // {node, visitedMask}
        for (int i=0; i<n; i++)
        {
            q.push({i,1<<i});
            dp[i][1<<i]=0;                    
        }
        while(!q.empty()){                        
            auto &[u, mask] = q.front(); 
            for ( auto v : graph[u]){
                int nmask = mask | (1 << v);
                if (dp[v][nmask] > dp[u][mask]+1){
                    dp[v][nmask] = dp[u][mask]+1;
                    q.push({v,nmask});
                }
            }
            q.pop();
        }
        
        int ans=INT_MAX;
        for (int i=0; i<n; i++)
            ans = min(ans, dp[i][ (1<<n)-1 ]);
        return ans;
    }
};