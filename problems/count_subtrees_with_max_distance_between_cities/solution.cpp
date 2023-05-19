class Solution {
public:
int dfs(vector<vector<int>> &G, int mask, int u, int &rmask, int &ret) {
    int dist = 0, max_dist = 0;    

    for (auto v : G[u])
        if (mask & (1 << v)) {
            rmask ^= (1 << v);
            dist = 1 + dfs(G,mask ^ (1 << v), v, rmask, ret);
            ret = max(ret, dist + max_dist);
            max_dist = max(max_dist, dist);
        }
    return max_dist;
}
vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
    vector<vector<int>> G(n);
    for (auto &e : edges) {
        G[e[0] - 1].push_back(e[1] - 1);
        G[e[1] - 1].push_back(e[0] - 1);
    }
    vector<int> ret(n - 1);
  
    for (int bits =3; bits< (1<< n); bits++){
        for (int u=0; u<n; u++){
            if ( bits & (1<<u)){
                int maxd=0, mask=bits ^ (1<<u);
                dfs(G,mask,u,mask,maxd);
                if (!mask && maxd) {
                    ret[maxd-1]++;
                    
                    break;
                }
            }
        }
          
    }
    return ret;
}
};