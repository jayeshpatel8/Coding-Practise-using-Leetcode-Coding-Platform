class Solution {
public:
vector<vector<int>> G;
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {    
        G = vector<vector<int>>(n,vector<int>());
        for (auto &e : edges)
            G[e[0]].push_back(e[1]),G[e[1]].push_back(e[0]);
        int ans = (dfs(0,-1,hasApple)-2);
        return ans >0 ? ans : 0;
    }
    int dfs(int u, int v, vector<bool>& hasApple){
        int sum = 0;
        for (auto i : G[u]){
            if (i==v) continue;
            sum += dfs(i,u,hasApple);
        }
        if (sum || hasApple[u])sum+=2;
        return sum;
    }
};