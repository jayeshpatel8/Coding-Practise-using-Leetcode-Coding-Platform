class Solution {
public:
    int longestPath(vector<int>& par, string s) {
        int  n = par.size();
        vector<vector<int>> vis(n,vector<int>(2));
        vector<int> cnt(n);
        for (int i = 1; i < n; ++i)
            ++cnt[par[i]];
        queue<int> q;
        for (int i = 1; i < n; ++i)
            if (cnt[i] == 0)
                q.push(i);
        
        while (!q.empty()){
            int sz = q.size();
            while (sz-- > 0){
                int i = q.front(); q.pop();
                int j = par[i];
                if (s[i] != s[j]){
                    int hi =1 + vis[i][0]  ;
                    if (vis[j][0]<hi)
                        vis[j][1] = vis[j][0] , vis[j][0]=hi;
                    else if (vis[j][1]<hi) 
                        vis[j][1]=hi;
                }
                if (--cnt[j] == 0)
                    if (j > 0)
                        q.push(j);
            }
        }
        int ans = -1;
        for (auto &i  : vis)           
            ans = max(ans, i[0]+i[1]+1);

        return ans;
    }
};