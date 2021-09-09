class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> g(n,vector<int>(n,n));
        for (auto &i : mines ) g[i[0]][i[1]]=0;
        for ( int ro = 0; ro<n; ro++){
            int l ,r, u, d;
            l=r=u=d=0;
            for (int c = 0 ,rc = n-1; c<n; c++,rc--){                
                if (g[ro][c]) g[ro][c] = min(g[ro][c], ++l );
                else 
                    l=0;
                if (g[ro][rc])
                    g[ro][rc] = min(g[ro][rc], ++r);
                else r=0;
                if (g[c][ro])
                    g[c][ro] = min(g[c][ro], ++u);
                else u = 0;
                if (g[rc][ro])
                    g[rc][ro] = min(g[rc][ro], ++d);
                else d = 0;
            }
        }
        int ans = 0;
        for(auto &i : g){
            for( auto j : i)
                ans = max(ans, j);
        }
        return ans;
    }
};