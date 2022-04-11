class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> g(n);
        for (auto &e : paths)
            g[e[0]-1].push_back(e[1]-1), g[e[1]-1].push_back(e[0]-1);
        vector<int> ans(n);
        for (int i=0; i<n; i++){
            bool used[5]={};
            for (auto c : g[i]) used[ans[c]]=1;
            for (int c=1; c<5; c++){
                if (used[c]) continue;
                ans[i]=c;break;
            }
        }
        return ans;
    }
};