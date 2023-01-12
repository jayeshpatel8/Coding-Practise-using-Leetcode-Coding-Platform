class Solution {
public:
    vector<vector<int>> G;
    vector<vector<int>> cnt;
    vector<int> ans;
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        G = vector<vector<int>>(n,vector<int>());
        cnt = vector<vector<int>>(n,vector<int>(26));
        ans.resize(n,0);
        for (auto &e : edges)
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
        dfs(0,-1, labels);
        return ans;
    }
    void dfs(int u, int par,string & labels){
        for (auto i : G[u]){
            if (i == par) continue;
            dfs(i,u,labels);
            for (int j=0; j<26; j++)
                cnt[u][j] +=cnt[i][j];
        }        
        ans[u] = ++cnt[u][labels[u]-'a'];        
    }
};