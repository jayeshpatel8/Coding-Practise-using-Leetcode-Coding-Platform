class Solution {
public:

    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans = 0, N =  bombs.size();
        vector<vector<int>> G(N);
        for (int i=0; i<bombs.size(); i++){
            long long x = bombs[i][0], y = bombs[i][1], r = (long long)bombs[i][2] * bombs[i][2] ;
            for (int j=0; j<bombs.size(); j++){
                if (i==j) continue;
                long long X =  x-bombs[j][0]  , Y =  y - bombs[j][1];
                if (X*X+Y*Y <= r)
                    G[i].push_back(j);
            }            
        }
        
        function<int(int, vector<bool> &)> dfs = [&](int i, vector<bool> &vis)->int{         
            vis[i]=1;
            int ans = 0;
            for (auto j : G[i])
                if (!vis[j])
                    ans += 1 + dfs(j,vis);
            return ans;
        };
        for (int i=0; i<N; i++){
            vector<bool> vis(N,0);
            ans= max(ans,1 + dfs(i,vis));
        }
        return ans;
    }
};