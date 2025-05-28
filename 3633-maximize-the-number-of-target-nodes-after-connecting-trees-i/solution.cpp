class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
        int m = e1.size() + 1, n = e2.size() + 1, max2 = 0;
        vector<vector<int>> g1(m + 1),g2(n+1);
        for (auto &e: e1) {
            g1[e[0]].push_back(e[1]);
            g1[e[1]].push_back(e[0]);            
        }

        for (auto &e: e2) {
            g2[e[0]].push_back(e[1]);
            g2[e[1]].push_back(e[0]);            
        }        
        vector<int> res(m);
        for (int i = 0; i < n; ++i)
            max2 = max(max2, dfs(i, -1, g2, k - 1));
        for (int i = 0; i < m; ++i)
            res[i] = max2 + dfs(i, -1, g1, k);        
        return res;
    }
    int dfs(int i, int p, vector<vector<int>> &al, int k) {
        if (k <= 0)
            return k == 0;
        int res = 1;
        for (int j : al[i])
            if (j != p)
                res += dfs(j, i, al, k - 1);
        return res;
    }
};
