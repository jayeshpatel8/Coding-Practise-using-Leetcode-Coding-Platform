class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if (n==1) return 1;
        vector<int> g[n+1];
        for (auto & i : edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> vis(n+1);
        queue<pair<int,double>> q;
        q.push({1,1.0});
        vis[1] = 1;
        double ans=0;
        while (!q.empty()&& t-- > 0 ){
            int sz = q.size();
            while (sz-- > 0){
                auto [i,p] = q.front(); q.pop();
                int c = 0;
                for (auto  j : g[i])
                    c +=!vis[j];
                if (c)
                    p /=c;
                
                for (auto  j : g[i]){
                    if (!vis[j]){
                        vis[j] = 1;                        
                        q.push({j,p});
                        if (target == j ){
                            if (t==0 ) return p;
                            int c = 0;
                            for (auto  k : g[j]) c +=!vis[k];
                            return  c == 0 ? p : 0;
                        }
                    }
                }
            }
        }
        return ans;
    }
};